
// Defines

#define Red 2
#define Blue 4

// Variables

bool ToggleR = false;
bool ToggleB = false;
unsigned long  LastTR = 0;
unsigned long  LastTB = 0;
int RT = 1000;
int BT = 1000;

// Functions

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
}

void loop() { 
  ToggleLed();
}
void ToggleLed() {

    if (millis() - LastTR >= RT) {
    LastTR = millis();
    TR();
  }
  if (millis() - LastTB >= BT) {
    LastTB = millis();
    TB(); 
  }
}
void TR() {
  if (!ToggleR) {
    digitalWrite(Red, HIGH);
    ToggleR = true;
  } else {
    digitalWrite(Red, LOW);
    ToggleR = false;
  }
}
void TB() {
  if (!ToggleB) {
    digitalWrite(Blue, HIGH);
    ToggleB = true;
  } else {
    digitalWrite(Blue, LOW);
    ToggleB = false;
  }
}
