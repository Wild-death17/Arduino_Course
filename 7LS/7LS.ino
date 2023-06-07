
#define Red 2
#define Blue 12
#define Green 4
#define Yellow 3
#define Read 205

int Leds[] = { Red, Blue, Green, Yellow };
int V;


void setup() {

  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  V = analogRead(A0);
  Serial.println(V);
  /* varse 1
  if (V >= 820)
    Light4();
  else if (V >= 615)
    Light3();
  else if (V >= 410)
    Light2();
  else if (V >= 205)
    Light1();
  else Light0();
  */
  /* varse 2
  switch (V / Read) {
    case 0:
      Light0();
      break;
    case 1:
      Light1();
      break;
    case 2:
      Light2();
      break;
    case 3:
      Light3();
      break;
    case 4:
      Light4();
      break;
  }
  */
  /* varse 3
  LightLeds(V / 205);
  */
  /* varse 4
  int NumOfLeds = map(V, 0, 1023, 0, 4);
  */
}

void LightLeds(int x) {
  for (int i = 0; i < x; i++)
    digitalWrite(Leds[i], HIGH);
  for (int i = 0; i < 4; i++)
    digitalWrite(Leds[i], LOW);
}
void Light0() {
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
}
void Light1() {
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
}
void Light2() {
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
}
void Light3() {
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Yellow, LOW);
}
void Light4() {
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Yellow, HIGH);
}
