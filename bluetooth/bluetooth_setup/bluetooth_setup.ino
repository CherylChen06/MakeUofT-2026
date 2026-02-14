/*
 * HC-05 AT Command Mode Configuration
 * This sketch allows you to send AT commands to configure the HC-05
 */

#include <SoftwareSerial.h>

#define BT_RX 10  // Connect to HC-05 TX
#define BT_TX 11  // Connect to HC-05 RX (through voltage divider)
#define BT_KEY 9  // Connect to HC-05 KEY/EN pin

SoftwareSerial BTSerial(BT_RX, BT_TX);

void setup() {
  pinMode(BT_KEY, OUTPUT);
  digitalWrite(BT_KEY, HIGH); // Enable AT command mode
  
  Serial.begin(9600);
  Serial.println("=== HC-05 AT Command Mode ===");
  Serial.println("Waiting 2 seconds for HC-05 to initialize...");
  
  delay(2000);
  
  BTSerial.begin(38400); // HC-05 default AT mode baud rate
  
  Serial.println("Ready! Type AT commands (must be UPPERCASE)");
  Serial.println("Example: AT");
  Serial.println("Note: Commands must end with newline (set in Serial Monitor)");
  Serial.println("=====================================\n");
}

void loop() {
  // Read from Bluetooth and send to Serial Monitor
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.write(c);
  }
  
  // Read from Serial Monitor and send to Bluetooth
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    BTSerial.print(command);
    BTSerial.print("\r\n"); // HC-05 needs CR+LF
    Serial.print("Sent: ");
    Serial.println(command);
  }
}