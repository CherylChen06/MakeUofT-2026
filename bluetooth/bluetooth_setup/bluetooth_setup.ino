#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);    // USB debug
  BT.begin(9600);        // HC-05 baud
  Serial.println("Master Ready");
}

void loop() {
  BT.println("Hello from Master");
  Serial.println("Sent: Hello from Master");
  delay(1000);
}