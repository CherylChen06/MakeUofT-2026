const int trigPin = 10;
const int echoPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;

  // Ensure clean LOW pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10µs HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(200);
}