
//define leds
#define Rled 11
#define Gled 6
#define Bled 9
#define Yled 10

//define buttons
#define BtnY 2
#define BtnB 3
#define BtnG 4
#define BtnR 12

//Led and btn count
#define ledCount 4
#define btnCount 4
#define Debounce 50

//Variables
int BtnVal, LastBtnVal, Temp = 0;
unsigned long LastTimeBtnPress;

//Array of all elements
int allBtn[btnCount] = { BtnR, BtnB, BtnG, BtnY };
int allLed[ledCount] = { Rled, Bled, Gled, Yled };
bool LedStatus[ledCount] = { false, false, false, false };

//Setup & Loop
void setup() {
  for (int i = 0; i < allBtn; i++) {
    pinMode(allBtn[i], INPUT_PULLUP);
    pinMode(allLed[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("started...");
}
void loop() {
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