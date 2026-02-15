#include "DFRobot_Heartrate.h"

#define heartratePin A0     // your heart rate sensor pin
#define buzzerPin 9         // connect a piezo buzzer or speaker here
#define ledPin 13           // optional LED to visualize beat

DFRobot_Heartrate heartrate(ANALOG_MODE);

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read sensor
  heartrate.getValue(heartratePin);

  // Check if heartbeat is detected
  uint16_t bpm = heartrate.getRate();

  if (bpm != 0) {
    // Heartbeat detected: beep and flash LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(80);  // duration of beep/flash
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);

    // Optional: print to serial
    Serial.println("Heartbeat detected! Beep!");
  }

  delay(10);  // small delay for stability
}
