
//Defines

#define pinBtnR 12
#define pinBtnB 3
#define pinBtnG 4
#define pinBtnY 2

#define Redled 11
#define Blueled 6
#define Greenled 9
#define Yellowled 10

//Arrey

int pinBtn[]={pinBtnR, pinBtnB, pinBtnG, pinBtnY};
int ledClr[]={Redled, Blueled, Greenled, Yellowled};

// Functions

void setup() {
   for (int i = 0 ; i < 4 ; i++)
   {
     pinMode(pinBtn[i], INPUT_PULLUP);
     pinMode(ledClr[i], OUTPUT);
   }
}

void loop() {
  for (int k = 0 ; k < 4 ; k++)
  {
    if (digitalRead (pinBtn[k])==LOW)
    //button is pressed
    {
      digitalWrite(ledClr[k], HIGH);
      digitalWrite(ledClr[k], LOW);
    }
  }
}

