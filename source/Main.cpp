#include "MicroBit.h"
#include "MicroBitUARTService.h"

//Deklaration von Variablen
MicroBit uBit;
MicroBitUARTService *uart;
enum menue { Temperatur, Licht, Magnet, Beschleunigung, Lage, Mikrophone};
static int mein = 0;

//Prototype von Funktionen
int getLightValue(void);
int selfMicroImpl(void);
ManagedString msg = "";

static bool connected = false;

//Diese Funktion liesst den Lichtsensor aus und gibt einen Wert zwischen 0-100 zurück
int getLightValue(void)
    {
        int value = 0;
        value = uBit.display.readLightLevel();
        return (value * 0.3921);      
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

//Hier werden die aktuellen G Krafte die auf den Calliope wirken berechnet.
int getgStrength()
{
  double x = uBit.accelerometer.getX();
  double y = uBit.accelerometer.getY();
  double z = uBit.accelerometer.getZ();

  return (int) sqrt(x*x + y*y + z*z);
}

//Sobald ein Geraet mit dem Calliope verbunden ist, wird diese Funktion aufgerufen (siehe main) --> messageBus.listen 
// Hier werden Mikro, Temperatur, Licht, Kompass-und Beschleunigungssensor ausgelesen und über Bluetooth verschickt
void onConnected(MicroBitEvent)
{
    uBit.display.scroll("C");
    uBit.rgb.setColour(0x00, 0x33, 0x33, 0xff);
    connected = true;
    mein ++;
    
    while(connected) {
        
        uart->send(ManagedString("M:")+ ManagedString(selfMicroImpl())+ ManagedString("\r\n") );
        //uart->send(ManagedString("M:"));
        //uart->send(ManagedString(selfMicroImpl()));
        //uart->send(ManagedString("\r\n"));
       
       uart->send(ManagedString("T:")+ ManagedString(uBit.thermometer.getTemperature()) + ManagedString("\r\n"));
        //uart->send(ManagedString("T:"));
        //uart->send(ManagedString(uBit.thermometer.getTemperature()));
        //uart->send(ManagedString("\r\n"));
        
        uart->send(ManagedString("L:")+ ManagedString(getLightValue()) + ManagedString("\r\n"));
        //uart->send(ManagedString("L:"));
        //uart->send(ManagedString(getLightValue()));
        //uart->send(ManagedString("\r\n"));
        
        uart->send(ManagedString("C:")+ ManagedString(uBit.compass.heading())+ ManagedString("\r\n") );
        //uart->send(ManagedString("C:"));
        //uart->send(ManagedString(uBit.compass.heading()));
        //uart->send(ManagedString("\r\n"));

        uart->send(ManagedString("AX:") +  ManagedString(uBit.accelerometer.getX()) + ManagedString("\r\n") );
        ///uart->send(ManagedString("AX:"));
        //uart->send(ManagedString(uBit.accelerometer.getX()));
        //uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AY:") +  ManagedString(uBit.accelerometer.getY()) + ManagedString("\r\n") );
        //uart->send(ManagedString("AY:"));
        //uart->send(ManagedString(uBit.accelerometer.getY()));
        //uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AZ:") +  ManagedString(uBit.accelerometer.getZ()) + ManagedString("\r\n") );
        //uart->send(ManagedString("AZ:"));
        //uart->send(ManagedString(uBit.accelerometer.getZ()));
        //uart->send(ManagedString("\r\n"));
        uart->send(ManagedString("AS:") +  ManagedString(getgStrength()) + ManagedString("\r\n") );
        //uart->send(ManagedString("AS:"));
        //uart->send(ManagedString(getgStrength()));
        //uart->send(ManagedString("\r\n"));

        uart->send(ManagedString("LA:") + ManagedString(uBit.accelerometer.getGesture()) + ManagedString("\r\n") );
        //uart->send(ManagedString("LA:"));
        //uart->send(ManagedString(uBit.accelerometer.getGesture()));
        //uart->send(ManagedString("\r\n"));
      
        msg = uart->read(1,ASYNC);
        uBit.display.scroll(msg);
        
        uBit.sleep(20);
    }
}

// Falls die Verbindung getrennt wird erscheint ein "D" auf dem Calliope --> messageBus.listen
void onDisconnected(MicroBitEvent)
{
    connected = false;
    uBit.rgb.setColour(0xff, 0x66, 0x66, 0xff);
    uBit.display.print("D");
    uBit.reset();  
}

//In der main ist ein messageBus.lister auf den Calliope Button A gesetzt. 
//Bei betatigen des Buttons wird diese Funktion aufgerufen.
void pressedButtonA(MicroBitEvent)
{
    uBit.display.print("A");
    
    if(connected) {
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

void pressedButtonAB(MicroBitEvent){
    //uBit.messageBus.ignore(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    //connected = false;
    uBit.rgb.setColour(0x00, 0x88, 0xff, 0xff);
    uBit.display.scroll("Choose");
    uBit.sleep(100);
    connected = true;   
}



int main()
{
    //Initialisierung der UBit Umgebung
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

    //Compass jedesmal neu kalibrieren
    //uBit.compass.calibrate();
    //Compass einmalig kalibrieren
    uBit.compass.heading();

    //WHITE
    uBit.rgb.setColour(0xff, 0xff, 0xff, 0xff);
    //In diesen Zeilen sind die MessageBus Listener definiert. 
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
    uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, pressedButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, pressedButtonB);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, pressedButtonAB);
    
    //Start of BluetoothUARTService
    uart = new MicroBitUARTService(*uBit.ble, 32, 32);

    //Start der zusätzlichen Services
    new MicroBitTemperatureService(*uBit.ble, uBit.thermometer);
    new MicroBitMagnetometerService(*uBit.ble, uBit.compass);

    //AccelerometerService deaktiviert da in Kombination mit UART einfriert.
    //new MicroBitAccelerometerService(*uBit.ble, uBit.accelerometer);

    //Falls der Calliope diese Funktion aufruft kann er in den Sleep Modus gehen.    
    release_fiber();
}