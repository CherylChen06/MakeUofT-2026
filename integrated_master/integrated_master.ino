#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9); // RX, TX

#define SPEAKER_PIN 6  // Master speaker

enum State {
  WAIT_FOR_CONNECTION,
  SEND_SIGNAL,
  ANIMATING,
  PLAYING
};

State currentState = WAIT_FOR_CONNECTION;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(SPEAKER_PIN, OUTPUT);

  Serial.println("MASTER: Booted, waiting for connection");
  showIdleScreen();
}

void loop() {

  switch(currentState){

    case WAIT_FOR_CONNECTION:
      Serial.println("MASTER: Waiting for Bluetooth connection...");
      // Optionally send a ping
      BT.write('P');

      if(BT.available()){
        char c = BT.read();
        Serial.print("MASTER: Received from slave -> ");
        Serial.println(c);
        currentState = SEND_SIGNAL;
      }
      delay(500);
      break;

    case SEND_SIGNAL:
      Serial.println("MASTER: Sending START signal to slave");
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
      currentState = WAIT_FOR_CONNECTION;
      showIdleScreen();
      break;
  }
}

// ---------- MASTER PLACEHOLDER FUNCTIONS ----------

void showIdleScreen(){
  Serial.println("MASTER DISPLAY: Idle");
}

void runAnimation(){
  Serial.println("MASTER animation running...");
  delay(2000); // simulate animation
}

void playMusic(){
  Serial.println("MASTER music playing...");

  // Example melody using the speaker
  tone(SPEAKER_PIN, 440, 500); // A4, 500ms
  delay(500);
  tone(SPEAKER_PIN, 494, 500); // B4, 500ms
  delay(500);
  noTone(SPEAKER_PIN);
} 