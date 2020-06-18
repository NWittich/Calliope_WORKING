# Calliope_WORKING
Dieses Repositorium beinhaltet den Code um alle Sensorwerte des Calliope V1.3 auszulesen und über Bluetooth LE UART zu versenden. 
Nach erolgreicher Kopplung mit dem Calliope fängt dieser an, die Sensorwerte zu senden.

Kodiert sind die Sensorwerte wie folgt:
* M: Mikrophonelautstärke (Bereich 0-100), 
* T: Temperatur (° C) , 
* L: Lichtintensität (Bereich 0-100) , 
* C: Grad (360° = Nord, 90° = Ost, 180° = Süd , 270° = West), 
* AX: Beschleunigung auf der x-Achse (in millig (Gravitation)) , 
* AY: Beschleunigung auf der y-Achse (in millig), 
* AZ: Beschleunigung auf der z-Achse (in millig), 
* AS: aktuell Wirkende Gravitation auf dem Calliope, 
* BA: Button A betätigt (0 falsch, 1 wahr) , 
* BB: Button B betätigt (0 falsch, 1 wahr)

## How to use

###### Installationsanleitung auf Calliope & Smartphone
1. Firmware auf Calliope flashen
   1. Calliope per USB an den PC anschließen
   1. Hex Datei welche unter build/calliope-mini-classic-gcc/source/fh-frankfurt-ss2020-combined.hex zu finden ist auf den Calliope kopieren
   1. Nach erfolgreichem flashen des Calliope leuchtet eine weiße LED
1. Smartphone mit Calliope koppeln
   1. Calliope starten
   1. Button A und Button B drücken
   1. Reset Button kurz antippen
   1. Sobald das Bluetooth Symbol auf dem Bildschirm des Calliope erscheint, Button A und Button B loslassen
   1. Calliope auf dem Smartphone Bluetooth Manager auswählen
   1. Zahlencode (PIN) der auf dem Calliope erscheint notieren und bei der Verbindungsanfrage auf dem Smartphone eingeben
   1. Mit folgender App können die Daten auf dem Smartphone angezeigt werden --> https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal
   
   
   ## Hardware
   
   <img src="https://github.com/calliope-mini/calliope-demo/blob/master/calliope-mini-v1.0.png" width="250"/>
 
   
   ## Entwicklungsumgebung
   
| Umgebung | Betriebssystem |
| ------------- |-------------|
| Visual Studio Code | Windows |
| Script  | Linux |
   
###### Windows
1. Installation von python [LINK](https://www.python.org/downloads/)
      * Wichtig während der Installation die Option “add to path” auswählen um die Umgebungsvariable zu setzen.
1. Installtion von CMAKE (Yotta nutzt CMake für den Buildprozess) [LINK](http://www.cmake.org/download/)
      * Wichtig während der Installation die Option “add to path” auswählen um die Umgebungsvariable zu setzen.
1. Installation von Ninja 1.10 [LINK](https://github.com/ninja-build/ninja/releases/download/v1.10.0/ninja-win.zip)
      * Die 

   
   
 

