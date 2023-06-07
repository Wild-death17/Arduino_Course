#define Red 2
#define Yellow 3
#define Green 4
#define Blue 12
int prd = 1000;

void setup() {
  pin(Red);
  pin(Yellow);
  pin(Green);
  pin(Blue);
  Serial.begin(9600);
}

void loop() {
  Serial.print("prd = ");
  Serial.println(prd);
  BlinkRed(GetNewPrd('G'));
  BlinkBlue(GetNewPrd('R'));
  BlinkGreen('g');
  BlinkYellow('r');
  prd = GetNewPrd('D');
}

void BlinkGreen(int x) {
  digitalWrite(Green, HIGH);
  delay(x);
  digitalWrite(Green, LOW);
  delay(x);
}
void BlinkRed(int x) {
  digitalWrite(Red, HIGH);
  delay(x);
  digitalWrite(Red, LOW);
  delay(x);
}
void BlinkBlue(int x) {
  digitalWrite(Blue, HIGH);
  delay(x);
  digitalWrite(Blue, LOW);
  delay(x);
}
void BlinkYellow(int x) {
  digitalWrite(Yellow, HIGH);
  delay(x);
  digitalWrite(Yellow, LOW);
  delay(x);
}
void pin(int x) {
  pinMode(x, OUTPUT);
}
void ON(int x) {
  digitalWrite(x, HIGH);
}
void OFF(int x) {
  digitalWrite(x, LOW);
}
void ChangePrd() {
  if (prd > 300) {
    prd -= 100;
  }
}
int GetNewPrd(int prd,char type) {
  int x;
  switch (type) {
    case 'G':
    case 'g':
      x = prd*2;
      break;
    case 'R':
    case 'r':
      x = prd*3;
      break;
    default:
      if (prd > 300)
      x = prd - 100;
      else
       x = prd;
  }
  return x;
  // if (prd > 300)
  //   return (prd - 100);
  // //when if doesnt have {} the if block is only one line length.
  // // works with every statement that has {}.
  // return prd;
}
