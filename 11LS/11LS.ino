
//Defines
#define Yaxis A5
#define Xaxis A6
#define HighPoint 800
#define LowPoint 200

#define Red 6
#define Blue 11
#define Green 10
#define Yellow 9
#define ledCount 4

//define Corn
#define DOWN 100
#define RAISE 200
#define UP 300
#define FADE 400

//Variables
int LastYaxisVal = 0;
int LastXaxisVal = 0;

//Array of all elements
bool isLedon[ledCount];
int CornVal[ledCount];
int CornState[ledCount];
int Leds[] = { Red, Blue, Green, Yellow };

//Setup & Loop
void setup() {
  Serial.begin(9600);
  Serial.println("started...");
  for (int i = 0; i < ledCount; i++) {
    isLedon[i] = false;
    CornState[i] = DOWN;
    pinMode(Leds[i], OUTPUT);
  }
}
void loop() {

  int Yval = analogRead(Yaxis);
  int Xval = analogRead(Xaxis);

  YaxisLed(Yval);
  XaxisLed(Xval);

  for (int x = 0; x < ledCount; x++) {
    switch (CornState[x]) {
      case DOWN:
        CornVal[x] = 0;
        if (isLedon[x])
          CornState[x] = RAISE;
        break;
      case UP:

        CornVal[x] = 255;
        if (isLedon[x])
          CornState[x] = FADE;
        break;
      case RAISE:
        CornVal[x]++;
        analogWrite(Leds[x], CornVal[x]);
        CornState[x] = (CornVal[x] >= 255) ? UP : RAISE;
        if (CornState[x] == UP)
          isLedon[x] = false;
        break;
      case FADE:
        CornVal[x]--;
        analogWrite(Leds[x], CornVal[x]);
        CornState[x] = (CornVal[x] <= 0) ? DOWN : FADE;
        if (CornState[x] == DOWN)
          isLedon[x] = false;
        break;
    }
  }
  delay(10);
}

//functions
void YaxisLed(int x) {
  if (x >= HighPoint && LastYaxisVal < HighPoint) {
    isLedon[0] = true;
  } else if (x <= LowPoint && LastYaxisVal > LowPoint) {
    isLedon[1] = true;
  }
  LastYaxisVal = x;
}
void XaxisLed(int x) {
  if (x >= HighPoint && LastXaxisVal < HighPoint) {
    isLedon[2] = true;
  } else if (x <= LowPoint && LastXaxisVal > LowPoint) {
    isLedon[3] = true;
  }
  LastXaxisVal = x;
}