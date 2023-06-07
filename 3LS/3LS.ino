//Defines
#define pinBtnR 2
#define pinBtnB 3
#define pinBtnG 4
#define pinBtnY 12

//Arrey
#define BTN_NUM 4
int pinBtn[BTN_NUM]={pinBtnR, pinBtnB, pinBtnG, pinBtnY};

// pinBtn[0]= pinBtnR;
// pinBtn[1]= pinBtnB;
// pinBtn[2]= pinBtnG;
// pinBtn[3]= pinBtnY;

// Functions
void setup() {
  for (int k = 0 ; k < BTN_NUM ; k++){
    pinMode(pinBtn[k],INPUT_PULLUP);
  }
  /*
  pinMode(pinBtnR, INPUT_PULLUP);
  pinMode(pinBtnB, INPUT_PULLUP);
  pinMode(pinBtnG, INPUT_PULLUP);
  pinMode(pinBtnY, INPUT_PULLUP);
  */
  pinMode(pinBtnR, OUTPUT);
  Serial.begin(9600);
  Serial.println("srarted..");
}

void loop() {
  for (int k = 0 ; k < BTN_NUM ; k++)
  {
    if (digitalRead (pinBtn[k])==LOW)
    //button is pressed
    RedOn();
  }
}
void RedOn()
{
  digitalWrite(pinBtnR, HIGH);
}




