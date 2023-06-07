
//define leds
#define Rled 11
#define Gled 6
#define Bled 9
#define Yled 10

//define CornState
#define DOWN 1
#define RAISE 2
#define UP 3
#define FADE 4

//Led count
#define ledCount 4
#define Debounce 50

//Variables
int Val, CornState = 0;
int BtnVal, LastBtnVal, Temp = 0;
unsigned long LastTimeBtnPress;

//Array of all elements

int allLed[ledCount] = { Rled, Bled, Gled, Yled };
bool LedStatus[ledCount] = { false, false, false, false };

//Setup & Loop
void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(allLed[i], OUTPUT);
  }
  CornState = DOWN;
  Serial.begin(9600);
  Serial.println("started...");
}
void loop() {
  switch (CornState) {
    case DOWN:
      Val = 0;
      CornState = RAISE;
      break;
    case RAISE:
      Val++;
      CornState = (Val >= 255) ? UP : RAISE;
      break;
    case UP:
      Val = 255;
      CornState = FADE;
      break;
    case FADE:
      Val--;
      CornState = (Val <= 1) ? DOWN : FADE;
      break;
  }
  analogWrite(Rled, Val);
  delay(10);
}

//functions
void turnLedon(int x) {
  LedStatus[x] = true;
  digitalWrite(allLed[x], HIGH);
}
void turnLedoff(int x) {
  LedStatus[x] = false;
  digitalWrite(allLed[x], LOW);
}
void toggleLed(int x) {
  if (!LedStatus[x]) {
    turnLedon(x);
  } else {
    turnLedoff(x);
  }
}
