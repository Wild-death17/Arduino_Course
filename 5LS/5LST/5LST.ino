
// Defines

#define Red 2
#define Blue 4
#define Btn 3

// Variables

bool ToggleRed = false;
bool ToggleBlue = false;
bool ToggleBtn = false;

unsigned long LastTRed = 0;
unsigned long LastTBlue = 0;

int RT = 1000;
int BT = 1000;

// Functions

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
  pinMode(Btn, INPUT_PULLUP);
}

void loop() {
  ToggleLed();
  if (digitalread(Btn) == LOW) {
    TBtn();
  }
}
void ToggleLed() {
  if (!ToggleBtn) {}
    if (millis() - LastTRed >= RT) {
      LastTRed = millis();
      TRed();
    }
    if (millis() - LastTBlue >= BT) {
      LastTBlue = millis();
      TBlue();
    }
  }

void TBtn() {
  if (!ToggleBtn) {
    ToggleBtn = true;
  } else {
    ToggleBtn = false;
  }
}
void TRed() {
  if (!ToggleRed) {
    digitalWrite(Red, HIGH);
    ToggleRed = true;
  } else {
    digitalWrite(Red, LOW);
    ToggleRed = false;
  }
}
void TBlue() {
  if (!ToggleBlue) {
    digitalWrite(Blue, HIGH);
    ToggleBlue = true;
  } else {
    digitalWrite(Blue, LOW);
    ToggleBlue = false;
  }
}
