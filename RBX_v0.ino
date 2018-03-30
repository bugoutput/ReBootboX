#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // change to your desired RX, TX pins 
int incomingByte = 0;   // for incoming serial data

void setup() {
  pinMode(2, OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port to match that of your modem
  mySerial.begin(9600);
  
}

void loop() { // run over and over
  digitalWrite(2, HIGH); // station power is up when this pin is High
  if (mySerial.available()) {
     // read the incoming byte:
    incomingByte = mySerial.read();

                // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, HEX);
    // change incomingByte to whatever you want your reboot signal to be:
    if (incomingByte == 140) {
      digitalWrite(2, LOW); // this powers down the station 
      Serial.print("Power-Down Signal Received... ");
      delay(60000);  // this is the time delay, in ms, before RBX powers station back up
      Serial.println(incomingByte, HEX);
      }
    }
}

