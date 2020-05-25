#include "MicroBit.h"
#include "MicroBitUARTService.h"
#include "Storage.h"
#include "Interpreter.h"
#include <cmath>


MicroBit uBit;
MicroBitUARTService *uart;
//Prototype
int getMicrophoneValue(void);
static int read(void);
int getLightValue(void);
int connected = 0;


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
        return max;
    }
    
    
}

int getMicrophoneValue(void)
    {
    int min = 1023;
    int max = 0;
    int value = 0;
    for (int i = 0; i < 32; i += 1) {
        value = uBit.io.P21.getAnalogValue();
        if ( value > max ) {
           max = value;
       } else if ( value < min ) {
           min = value;
       }
    }
    return (( max - min ) * 0.0977);
    }



void onConnected(MicroBitEvent)
{
    uBit.display.scroll("C");
    uBit.rgb.setColour(0x00, 0x33, 0x33, 0xff);
    connected = 1;
    
    while(connected == 1) {
        /*
        uart->send(ManagedString("T:"));
        uart->send(ManagedString(uBit.thermometer.getTemperature()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
        //uart->send(ManagedString("C:"));
        //uart->send(ManagedString(uBit.compass.heading()));
        //uart->send(ManagedString("\r\n"));
        //uBit.sleep(500);
        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
        uart->send(ManagedString("M:"));
        uart->send(ManagedString(read()));
        uart->send(ManagedString("\r\n"));
        
        uart->send(ManagedString("\r\n"));
        */
        uart->send(ManagedString("M:"));
        uart->send(ManagedString(selfMicroImpl()));
        uart->send(ManagedString("\r\n"));
       
        uart->send(ManagedString("T:"));
        uart->send(ManagedString(uBit.thermometer.getTemperature()));
        uart->send(ManagedString("\r\n"));

        //uBit.sleep(1000);
        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));

        uart->send(ManagedString("C:"));
        uart->send(ManagedString(uBit.compass.heading()));
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
        uBit.rgb.off();
    }
    //uBit.display.clear();
}

const int threshold = 519;

static int read()
{
    int mic = 0;
    const int n = 30;
    for (uint8_t i = 0; i < n; i++) {
        const int v = uBit.io.P21.getAnalogValue();
        uart->send(ManagedString(v));
        uart->send(ManagedString("\r\n"));
        if (v > mic) mic = v;
    }

    if (mic < threshold) {
        return 0;
    }

    // mic 512...900 ~> 0...5
    const int gauge = static_cast<const int>((log2(mic - threshold + 1) * 5) / 8);

    // uBit.serial.printf("m:%d -> g:%d\n", mic, gauge);

    if (gauge < 0) {
        return 0;
    }

    if (gauge > 5) {
        return 5;
    }

    return gauge;
}





void pressedButtonB(MicroBitEvent)
{
    /*uBit.rgb.setColour(0xff, 0x00, 0x00, 0x00);
    int gauges[5] = {};
    while(true){for (uint8_t i = 0; i < (5-1); i++) {
            gauges[i] = gauges[i+1];
        }

        gauges[4] = read();

        for (uint16_t x = 0; x < 5; x++) {
            const int gauge = gauges[x];
            for (uint16_t y = 0; y < 5; y++) {
                const uint8_t t = static_cast<uint8_t>(gauge > y ? 255 : 0);
                uBit.display.image.setPixelValue(x, 4-y, t);
            }
        }

        int sum = 0;
        for (uint8_t i = 0; i < 5; i++) {
            sum += gauges[i];
        }


        for (uint8_t i=0; i < 5; i++){
            uart->send(ManagedString(gauges[i]));
            uart->send(ManagedString("\r\n"));
        }

        if (sum > 5*2.5) {
            uBit.rgb.setColour(0xFF, 0x00, 0x00, 0x00);
        } else {
            uBit.rgb.setColour(0x00, 0xFF, 0x00, 0x00);
        }

        uBit.sleep(100);
    }
    */
    AnalogIn u2(p3);
    
    
    for (int n=0; n<50;n++){
        uart->send(ManagedString(int(u2.read()*255)));
        uart->send(ManagedString("\r\n"));
        wait_us(500);
    }
    
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
    uart = new MicroBitUARTService(*uBit.ble, 32, 32);

    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);
    //uBit.display.scroll(ManagedString("MicroBitTemperatureService\r\n"));
    
    //while(true){
    //uBit.display.scroll(ManagedString("Calliope Demo v1.3\r\n"));
    //uBit.display.scroll(ManagedString(uBit.compass.heading()));
    //uBit.sleep(500);
    //}
    release_fiber();
}