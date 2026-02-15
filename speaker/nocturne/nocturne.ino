#define SPK 6

#define Bb4 466
#define B4 494
#define C5 523
#define D5 587
#define Eb5 622
#define F5 698
#define G5 784
#define Ab5 831
#define Bb5 932
#define C6 1047
#define D6 1175

#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440

#include <DFRobot_Heartrate.h>

#define SENSOR_PIN A0

DFRobot_Heartrate heartrate(ANALOG_MODE);

int notes[] = {
  Bb4, G5, F5, G5, F5, Eb5, Bb4,
  G5, C5, D5, C5, B4, C5, C6, G5, Bb5, Ab5, G5,
  F5, G5, D5, Eb5, C5, 
  Bb4, D6, C6, Bb5, Ab5, G5, Ab5, C5, D5, Eb5
};

int dur[] = {
  150,500,150,150,450,300,150,
  300,60,60,60,60,60,300,150,450,300,150,
  450,300,150,450,450,
  150,150,150,75,75,75,75,75,75,450
};

int rickroll[] = {
  C4, D4, F4, D4, A4, A4, G4, 
  C4, D4, F4, D4, G4, G4, F4, E4, D4, 
  C4, D4, F4, D4, F4, G4, E4, D4, C4, C4, G4, F4,
  C4, D4, F4, D4, A4, A4, G4,
  C4, D4, F4, D4, C5, E4, F4, E4, D4,
  C4, D4, F4, D4, F4, G4, E4, D4, C4, C4, G4, F4
};

int dur1[] = {
  75, 75, 75, 75, 225, 225, 450,
  75, 75, 75, 75, 225, 75, 225, 75, 150, 
  75, 75, 75, 75, 300, 150, 225, 75, 300, 150, 300, 600,
  75, 75, 75, 75, 225, 225, 450,
  75, 75, 75, 75, 300, 150, 225, 75, 150,
  75, 75, 75, 75, 300, 150, 225, 75, 300, 150, 300, 600
};

void setup() {
  Serial.begin(115200);
  for(int i=0;i<33;i++){
    tone(SPK, notes[i], dur[i]);
    delay(dur[i]*2.8);
      uint16_t rate = heartrate.getValue(SENSOR_PIN);

  if(rate){
    Serial.print("Heart Rate: ");
    Serial.println(rate/10);
  }

  delay(20);
  }

  delay(5000);

  for(int i=0;i<56;i++){
    tone(SPK, rickroll[i], dur1[i]);
    delay(dur1[i]*1.5);
      uint16_t rate = heartrate.getValue(SENSOR_PIN);

  if(rate){
    Serial.print("Heart Rate: ");
    Serial.println(rate/10);
  }

  delay(20);
  }
}

void loop(){
  uint16_t rate = heartrate.getValue(SENSOR_PIN);

  if(rate){
    Serial.print("Heart Rate: ");
    Serial.println(rate/10);
  }

  delay(500);
}
