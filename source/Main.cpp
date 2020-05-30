#include "MicroBit.h"
#include "MicroBitUARTService.h"

//Deklaration von Variablen
MicroBit uBit;
MicroBitUARTService *uart;
ManagedString msg;

//Prototype von Funktionen
int getLightValue(void);
int selfMicroImpl(void);
void lightLevelSend(MicroBitEvent);
static int connected = 0;


//Diese Funktion liesst den Lichtsensor aus und gibt einen Wert zwischen 0-100 zurück
int getLightValue(void)
    {
        int value = 0;
        value = uBit.display.readLightLevel();
        return (value * 0.3921);      
    }

 //Diese Funktion ist die Callbackfunktion des messageBus.lister welche in der Main definiert ist   
void lightLevelSend(MicroBitEvent){
    if(connected == 1) {
        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
    }
}


//Diese Funktion definiert,dass p3 ein Eingangssignal ist und über die Schleife 
//werden 100 Samples gemessen, der hoechste Wert wird in der Variablen max gespeichert.
//Der Rückgabewert ist ein Int zwischen 0-100
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

//Sobald ein Geraet mit dem Calliope verbunden ist, wird diese Funktion aufgerufen (siehe main) --> messageBus.listen 
// Hier werden Mikro, Temperatur, Licht, Kompass-und Beschleunigungssensor ausgelesen und über Bluetooth verschickt
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
        //msg = msg + ManagedString("M:")+ ManagedString(selfMicroImpl()); 
        
        uart->send(ManagedString("T:"));
        uart->send(ManagedString(uBit.thermometer.getTemperature()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
        //msg = msg + ManagedString("T:") + ManagedString(uBit.thermometer.getTemperature());
        
        uart->send(ManagedString("L:"));
        uart->send(ManagedString(getLightValue()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
        //msg = msg + ManagedString("L:") + ManagedString(getLightValue());

        uart->send(ManagedString("C:"));
        uart->send(ManagedString(uBit.compass.heading()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
        //msg = msg + ManagedString("C:") + ManagedString(uBit.compass.heading());

        uart->send(ManagedString("AX:"));
        uart->send(ManagedString(uBit.accelerometer.getX()));
        uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AY:"));
        uart->send(ManagedString(uBit.accelerometer.getY()));
        uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AZ:"));
        uart->send(ManagedString(uBit.accelerometer.getZ()));
        uart->send(ManagedString("\r\n"));
        uBit.sleep(20);
        //msg = msg + ManagedString("AX:") + ManagedString(uBit.accelerometer.getX()) + ManagedString("AY:") + ManagedString(uBit.accelerometer.getY()) + ManagedString("AZ:") + ManagedString(uBit.accelerometer.getZ());
        uBit.sleep(20);
         
        
        //uart->send(msg);
        uart->send(ManagedString("\r\n"));
        uBit.sleep(1000);
        //uart-> send(ManagedString(uart->size()));
        //msg = ManagedString("");
    }
}

// Falls die Verbindung getrennt wird erscheint ein "D" auf dem Calliope --> messageBus.listen
void onDisconnected(MicroBitEvent)
{
    connected = 0;
    uBit.rgb.setColour(0xff, 0x66, 0x66, 0xff);
    uBit.display.scroll("D");    
}

//In der main ist ein messageBus.lister auf den Calliope Button A gesetzt. 
//Bei betatigen des Buttons wird diese Funktion aufgerufen.
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

//In der main ist ein messageBus.lister auf den Calliope Button B gesetzt. 
//Bei betatigen des Buttons wird diese Funktion aufgerufen.
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
    uBit.accelerometer.setPeriod(30);
    
    //WHITE
    uBit.rgb.setColour(0xff, 0xff, 0xff, 0xff);

    //In diesen Zeilen sind die MessageBus Listener definiert. 
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, pressedButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, pressedButtonB);
    
    //uBit.messageBus.listen(MICROBIT_ID_DISPLAY, MICROBIT_DISPLAY_EVT_LIGHT_SENSE, lightLevelSend);

    //Start of BluetoothUARTService
    uart = new MicroBitUARTService(*uBit.ble, 32, 32);
    //Start der zusätzlichen Services
    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);
    new MicroBitMagnetometerService(*uBit.ble, uBit.compass);
    new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);

    //uBit.display.readLightLevel();

    //Falls der Calliope diese Funktion aufruft kann er in den Sleep Modus gehen.    
    release_fiber();
}