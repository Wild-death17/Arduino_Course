
//Defines
#define Yaxis A2
#define Xaxis A3
#define HighPoint 800
#define LowPoint 200

#define Red 2
#define Blue 12
#define Green 4
#define Yellow 3

//Variables
int LastYaxisVal = 0;
int LastXaxisVal = 0;

//Array of all elements
int Leds[] = { Yellow, Blue, Red, Green };
bool isLedon[] = { false, false, false, false };

//Setup & Loop
void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
}
void loop() {
  int Yval = analogRead(Yaxis);
  YaxisLed(Yval);
  int Xval = analogRead(Xaxis);
  XaxisLed(Xval);
}

//functions
void YaxisLed(int x) {
  if (x >= HighPoint && LastYaxisVal < HighPoint) {
    Ledoff(1);
    ToggleLeds(0);
  } else if (x <= LowPoint && LastYaxisVal > LowPoint) {
    Ledoff(0);
    ToggleLeds(1);
  }
  LastYaxisVal = x;
}
void XaxisLed(int x) {
  if (x >= HighPoint && LastXaxisVal < HighPoint) {
    Ledoff(3);
    ToggleLeds(2);
  } else if (x <= LowPoint && LastXaxisVal > LowPoint) {
    Ledoff(2);
    ToggleLeds(3);
  }
  LastXaxisVal = x;
}
void ToggleLeds(int x) {
  if (!isLedon[x]) {
    Ledon(x);
  } else {
    Ledoff(x);
  }
}
void Ledon(int x) {
  isLedon[x] = true;
  digitalWrite(Leds[x], HIGH);
}
void Ledoff(int x) {
  isLedon[x] = false;
  digitalWrite(Leds[x], LOW);
}
