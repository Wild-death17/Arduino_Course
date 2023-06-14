// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
#define SoundSpeed 0.034
// defines variables
int distance;
long duration;
float MaxWaitTimeInCm = 100 * 2 / SoundSpeed;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  sendTrig();
  duration = pulseIn(echoPin, HIGH, MaxWaitTimeInCm);
  // Calculating the distance
  distance = duration * SoundSpeed / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
void sendTrig() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
