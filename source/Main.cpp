#include "MicroBit.h"
#include "MicroBitUARTService.h"
#include "Storage.h"
#include "Interpreter.h"

MicroBit uBit;
MicroBitUARTService *uart;
int getMicrophoneValue(void);
int getMicrophoneValue(void);

int connected = 0;


int getLightValue(void)
    {
        int value = 0;
        value = uBit.display.readLightLevel();
        return (value * 0.3921);
        
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
    connected = 1;
    // mobile app will send ASCII strings terminated with the colon character
    //ManagedString eom(":");
    while(connected == 1) {
    //    ManagedString msg = uart->readUntil(eom);
    //    msg = msg.substring(0, (msg.length())-2);
    //    uBit.display.scroll(msg);
        uart->send(ManagedString("T:"));
        uart->send(ManagedString(uBit.thermometer.getTemperature()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
        uart->send(ManagedString("C:"));
        uart->send(ManagedString(uBit.compass.heading()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
        uart->send(ManagedString("M:"));
        uart->send(ManagedString(getMicrophoneValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(500);
    }
}


void onDisconnected(MicroBitEvent)
{
    uBit.display.scroll("D");
    connected = 0;
}

void pressedButtonA(MicroBitEvent)
{
    uBit.display.print("A");
}

void pressedButtonB(MicroBitEvent)
{
    uBit.display.print("B");
}




int main()
{
    uBit.init();
    uBit.accelerometer.updateSample();

    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, pressedButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, pressedButtonB);
    uart = new MicroBitUARTService(*uBit.ble, 32, 32);

    //while(true){
    //uBit.display.scroll(ManagedString("Calliope Demo v1.3\r\n"));
    //uBit.display.scroll(ManagedString(uBit.compass.heading()));
    //uBit.sleep(500);
    //}
    release_fiber();
}