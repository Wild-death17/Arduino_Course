
#define Btn 2
#define GrnLed 3
#define RedLed 4
#define Debounce 50

bool IsLedOn = false;
int OnPrd = 1000;
int OffPrd;
int Score;
int BtnVal = digitalRead(Btn);
int LastBtnVal = digitalRead(Btn);

unsigned long LastTimeOn;
unsigned long LastTimeBtnPress = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RedLed, OUTPUT);
  pinMode(Btn, INPUT_PULLUP);
  randomSeed(analogRead(A1));
}
void loop() {
  BtnVal = digitalRead(Btn);
  if ((BtnVal == LOW) && (LastBtnVal == HIGH) && (millis() - LastTimeBtnPress >= Debounce)){
    LastTimeBtnPress = millis();
    Score += (IsLedOn) ? 1:-1;
    OnPrd = difficulty(Score);
    Serial.println(Score);
    Serial.println(OnPrd);}
  LastBtnVal = BtnVal;

  if ( millis() - LastTimeOn >= OnPrd ){
    ToggleLed();}
  if ( millis() - LastTimeOn >= OffPrd ){
    ToggleLed();}
}
int ChangePrd(){
  int k = random(500, 2000);
  return k;
}
void ToggleLed() {
  LastTimeOn = millis();
  if (!IsLedOn) {
    LedOn();
  } else {
    LedOff();
  }
}
void LedOn() {
  digitalWrite(RedLed, HIGH);
  IsLedOn = true;
  Serial.println("ledon");
}
void LedOff() {
  digitalWrite(RedLed, LOW);
  OffPrd = ChangePrd();
  IsLedOn = false;
  Serial.println("ledoff");
}
int difficulty(int x){
  switch(x){

    case 0:
    x = 1000;
    return x;
    break;
    
    case 1:
    x = 900;
    return x;
    break;
    
    case 2:
    x = 800;
    return x;
    break;
    
    case 3:
    x = 700;
    return x;
    break;
    
    case 4:
    x = 600;
    break;
    
    case 5:
    x = 500;
    return x;
    break;
    
    case 6:
    x = 400;
    return x;
    break;
    
    case 7:
    x = 300;
    return x;
    break;
    
    case 8:
    x = 200;
    return x;
    break;
    
    case 9:
    x = 100;
    return x;
    break; 
  }
}