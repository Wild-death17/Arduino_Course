#define pinBtnR 2
#define pinBtnY 3
#define pinBtnG 4
#define pinBtnB 12

#define pinLedB 6
#define pinLedR 9
#define pinLedY 11
#define pinLedG 10

#define BTN_NUM 4
int pinBtn[BTN_NUM] = { pinBtnR, pinBtnB, pinBtnY, pinBtnG };
int pinLed[BTN_NUM] = { pinLedR, pinLedB, pinLedY, pinLedG };
bool isLedOn[BTN_NUM] = { false, false, false, false };

void setup() {
  for (int k = 0; k < BTN_NUM; k++) {
    pinMode(pinBtn[k], INPUT_PULLUP);
    pinMode(pinLed[k], OUTPUT);
    LedOff(k);
  }

  Serial.begin(9600);
  Serial.println("started..");
}
void loop() {
  for (int k = 0; k < BTN_NUM; k++) {
    if (digitalRead(pinBtn[k]) == LOW) {
      toggleLed(k);
      while (digitalRead(pinBtn[k]) == LOW)
        delay(50);
    }
  }
}
void toggleLed(int chnl) {
  if (!isLedOn[chnl]) {
    LedON(chnl);
  } else {
    LedOff(chnl);
  }
}
void LedON(int chnl) {
  isLedOn[chnl] = true;
  digitalWrite(pinLed[chnl], HIGH);
}
void LedOff(int chnl) {
  isLedOn[chnl] = false;
  digitalWrite(pinLed[chnl], LOW);
}
