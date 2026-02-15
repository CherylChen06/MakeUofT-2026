#include <SoftwareSerial.h>
SoftwareSerial BT(8,9); // RX, TX

enum State {
  IDLE,
  CONNECTED,
  ANIMATING
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("SLAVE: Booted");
  showIdleScreen();
}

void loop() {

  // Check for master signal
  if(BT.available()){
    char c = BT.read();
    Serial.print("SLAVE received: ");
    Serial.println(c);

    if(c == 'S' && currentState == IDLE){
      Serial.println("SLAVE: Start animation signal received");
      currentState = CONNECTED;
    }
  }

  // ---------- State Machine ----------
  switch(currentState){

    case IDLE:
      break;

    case CONNECTED:
      Serial.println("STATE → CONNECTED");
      showConnectedScreen();
      currentState = ANIMATING;
      break;

    case ANIMATING:
      Serial.println("STATE → ANIMATING");
      runAnimation();
      currentState = IDLE; // back to idle after animation
      showIdleScreen();
      break;
  }
}

// ---------- SLAVE PLACEHOLDER FUNCTIONS ----------

void showIdleScreen(){
  Serial.println("SLAVE DISPLAY: Idle");
}

void showConnectedScreen(){
  Serial.println("SLAVE DISPLAY: Connected");
}

void runAnimation(){
  Serial.println("SLAVE animation running...");
  delay(2000); // simulate animation
}