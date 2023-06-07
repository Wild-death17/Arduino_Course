/*
#define LedR 2
#define Val 205
int arrey[] = { 4000, 2000, 1200, 400, 150 };
int dial = analogRead(A0);
unsigned long LasTimeon = 0;
bool IsLedOn = false;
void setup() {
  pinMode(LedR, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  dial = analogRead(A0);
  if (millis() - LasTimeon >= arrey[dial / Val]) {
    ToggleLed();
      LasTimeon = millis();
    Serial.println(arrey[dial / Val]);
  }
}
void ToggleLed() {
  if (!IsLedOn) {
    digitalWrite(LedR, HIGH);
    IsLedOn = true;
  } else {
    digitalWrite(LedR, LOW);
    IsLedOn = false;
  }
}
*/
/*
bool IsLedOn = false;
int LasTimeon = 0;
int PrdArr[] = { 4000, 2000, 1200, 400, 150 };
void setup() {
    pinMode(2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
int potz_val = map(analogRead(A0), 0, 1023, 0, 4);
int Prd =  PrdArr[potz_val];
  if (millis() - LasTimeon >= Prd) {
    ToggleLed();
      LasTimeon = millis();
}}
void ToggleLed() {
  if (!IsLedOn) {
    digitalWrite(2, HIGH);
    IsLedOn = true;
  } else {
    digitalWrite(2, LOW);
    IsLedOn = false;
  }
}
*/
