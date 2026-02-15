#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);

enum State {
  IDLE,
  SEND_SIGNAL,
  ANIMATING,
  PLAYING
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("MASTER: Booted");
  showIdleScreen();
}

void loop() {

  switch(currentState){

    case IDLE:
      // trigger condition can be button or sensor later
      Serial.println("MASTER: Triggering start");
      currentState = SEND_SIGNAL;
      delay(2000);   // just for demo
      break;


    case SEND_SIGNAL:
      Serial.println("MASTER: Sending S");
      BT.write('S');
      currentState = ANIMATING;
      break;


    case ANIMATING:
      Serial.println("MASTER: Running animation");
      runAnimation();
      currentState = PLAYING;
      break;


    case PLAYING:
      Serial.println("MASTER: Playing music");
      playMusic();
      currentState = IDLE;
      showIdleScreen();
      break;
  }
}

void showIdleScreen(){
  Serial.println("MASTER DISPLAY: Idle");
}

void runAnimation(){
  Serial.println("MASTER animation...");
  delay(2000);
}

void playMusic(){
  Serial.println("MASTER music...");
  delay(2000);
}