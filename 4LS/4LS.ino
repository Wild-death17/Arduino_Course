
//Defines

#define pinBtnY 2
#define pinBtnB 3
#define pinBtnG 4
#define pinBtnR 12

#define Redled 6
#define Greenled 10
#define Blueled 11
#define Yellowled 9

bool isLedon = false;
//Arrey

int pinBtn[] = { pinBtnR, pinBtnB, pinBtnG, pinBtnY };
int ledClr[] = { Redled, Blueled, Greenled, Yellowled };

// Functions

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pinBtn[i], INPUT_PULLUP);
    pinMode(ledClr[i], OUTPUT);
  }
}

void loop() {
  for (int k = 0; k < 4; k++) {

    if (digitalRead(pinBtn[k]) == LOW) {
      //button is pressed
      ToggleLed(k);
    }
  }
}
void ToggleLed(int chnl) {
  if (!isLedon) {
    lon(chnl);
  } else {
    loff(chnl);
  }
}

void lon(int chnl) {
  isLedon = true;
  digitalWrite(ledClr[chnl], HIGH);
}

void loff(int chnl) {
  isLedon = false;
  digitalWrite(ledClr[chnl], LOW);
}
