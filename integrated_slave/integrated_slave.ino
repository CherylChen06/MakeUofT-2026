#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);

enum State {
  IDLE,
  CONNECTED,
  ANIMATING,
  PLAYING
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("SLAVE: Booted");
  showIdleScreen();
}

void loop() {

  if(BT.available()){
    char c = BT.read();

    Serial.print("SLAVE got: ");
    Serial.println(c);

    if(c == 'S' && currentState == IDLE){
      Serial.println("SLAVE: Start command received");
      currentState = CONNECTED;
    }
  }

  switch(currentState){

    case IDLE:
      break;


    case CONNECTED:
      Serial.println("SLAVE: Connected state");
      showConnectedScreen();
      currentState = ANIMATING;
      break;


    case ANIMATING:
      Serial.println("SLAVE: Animation start");
      runAnimation();
      currentState = PLAYING;
      break;


    case PLAYING:
      Serial.println("SLAVE: Music start");
      playMusic();
      currentState = IDLE;
      showIdleScreen();
      break;
  }
}

void showIdleScreen(){
  Serial.println("SLAVE DISPLAY: Idle");
}

void showConnectedScreen(){
  Serial.println("SLAVE DISPLAY: Connected");
}

void runAnimation(){
  Serial.println("SLAVE animation...");
  delay(2000);
}

void playMusic(){
  Serial.println("SLAVE music...");
  delay(2000);
}