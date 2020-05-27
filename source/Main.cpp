#include "MicroBit.h"
#include "MicroBitUARTService.h"
#include "MicroBitAccelerometerService.h"
#include "MicroBitMagnetometerService.h"
#include "MicroBitTemperatureService.h"
#include "Storage.h"
#include "Interpreter.h"
#include <cmath>


MicroBit uBit;
MicroBitUARTService *uart;
MicroBitAccelerometerService *accservice;
MicroBitMagnetometerService *magservice;
MicroBitTemperatureService *tempservice;
//Prototype

int getLightValue(void);
int selfMicroImpl(void);
static int connected = 0;


int getLightValue(void)
    {
        int value = 0;
        value = uBit.display.readLightLevel();
        return (value * 0.3921);      
    }

int selfMicroImpl(void){
    AnalogIn microin(p3);

    int max = 0;
    int value = 0;

    for (int i=0; i<100; i+=1){
        value = int(microin.read()*255);
        if ( value < 127 ) {
           //Error Messung
            } 
       else if ( value > max ) {
            max = value;
            }
    }   
    max = (max * 0.7875) - 100;

    if (max > 100){
        return 100;
    }
    else{
        if (max < 0){
            return 0;
        }
        else {
            return max;
        }
    }
    
    
}

void onConnected(MicroBitEvent)
{
    uBit.display.scroll("C");
    uBit.rgb.setColour(0x00, 0x33, 0x33, 0xff);
    connected = 1;
    
    while(connected == 1) {
        uart->send(ManagedString("M:"));
        uart->send(ManagedString(selfMicroImpl()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
       
        uart->send(ManagedString("T:"));
        uart->send(ManagedString(uBit.thermometer.getTemperature()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);

        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);

        uart->send(ManagedString("C:"));
        uart->send(ManagedString(uBit.compass.heading()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);

        uart->send(ManagedString("AX:"));
        uart->send(ManagedString(uBit.accelerometer.getX()));
        uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AY:"));
        uart->send(ManagedString(uBit.accelerometer.getY()));
        uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AZ:"));
        uart->send(ManagedString(uBit.accelerometer.getZ()));
        uart->send(ManagedString("\r\n"));
      
        uart->send(ManagedString("\r\n"));
        uBit.sleep(1000);
    }
}


void onDisconnected(MicroBitEvent)
{
    connected = 0;
    uBit.rgb.setColour(0xff, 0x66, 0x66, 0xff);
    uBit.display.scroll("D");    
}

void pressedButtonA(MicroBitEvent)
{
    uBit.display.print("A");
    
    if(connected == 1) {
        //GREEN
        uBit.rgb.setColour(0x00, 0x66, 0x00, 0xff);
        // Receive until end of message signed by :
        ManagedString eom(":");
        ManagedString msg = uart->readUntil(eom);
        msg = msg.substring(0, (msg.length())-2);
        //RED
        uBit.rgb.setColour(0xff, 0x00, 0x00, 0x00);
        uBit.display.scroll(msg);
        //LED OFF
        uBit.rgb.setColour(0x00, 0x00, 0x00, 0x00);
    }
    //uBit.display.clear();
}

int pixel_from_g(int value)
{
    int x = 0;

    if (value > -750)
        x++;
    if (value > -250)
        x++;
    if (value > 250)
        x++;
    if (value > 750)
        x++;

    return x;
}

void pressedButtonB(MicroBitEvent)
{
        for (int i=0 ; i < 50; i++){
        int x = pixel_from_g(uBit.accelerometer.getX());
        int y = pixel_from_g(uBit.accelerometer.getY());

        uBit.display.image.clear();
        uBit.display.image.setPixelValue(x, y, 255);
        
        uBit.sleep(100);
        }
        uBit.display.image.clear();
}




int main()
{
    uBit.init();

    /*
    
    //GREEN
    uBit.rgb.setColour(0x00, 0x66, 0x00, 0xff);
    //RED
    uBit.rgb.setColour(0xff, 0x00, 0x00, 0x00);
    //WHITE
    uBit.rgb.setColour(0xff, 0xff, 0xff, 0xff);
    //LED OFF
    uBit.rgb.off();
    */
    //uBit.soundmotor.soundOn(261.626);

    uBit.accelerometer.updateSample();
    
    //WHITE
    uBit.rgb.setColour(0xff, 0xff, 0xff, 0xff);

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, pressedButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, pressedButtonB);
    
    //Start of BluetoothUARTService
    uart = new MicroBitUARTService(*uBit.ble, 32, 32);

    tempservice = new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);
    magservice = new MicroBitMagnetometerService(*uBit.ble, uBit.compass);
    accservice = new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);
    //uBit.display.scroll(ManagedString("MicroBitTemperatureService\r\n"));
    
    
    release_fiber();
}