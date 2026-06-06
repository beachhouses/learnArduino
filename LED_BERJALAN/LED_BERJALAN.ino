int led[] = {2,3,4,5,6,7,8,9};
int buttonPin = 10;

int mode = 0;
bool lastButtonState = HIGH;

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(led[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && lastButtonState == HIGH) {
    mode++;
    if(mode > 3) mode = 0;
    delay(200); // debounce
  }

  lastButtonState = buttonState;

  switch(mode) {

    case 0: // Knight Rider
      for(int i=0; i<8; i++) {
        cekTombol();
        nyalakanSatu(i);
      }

      for(int i=6; i>0; i--) {
        cekTombol();
        nyalakanSatu(i);
      }
      break;

    case 1: // Wave
      for(int i=0; i<8; i++) {
        cekTombol();
        digitalWrite(led[i], HIGH);
        delay(100);
      }

      for(int i=0; i<8; i++) {
        cekTombol();
        digitalWrite(led[i], LOW);
        delay(100);
      }
      break;

    case 2: // Polisi
      for(int i=0; i<4; i++)
        digitalWrite(led[i], HIGH);

      delay(200);

      for(int i=0; i<4; i++)
        digitalWrite(led[i], LOW);

      for(int i=4; i<8; i++)
        digitalWrite(led[i], HIGH);

      delay(200);

      for(int i=4; i<8; i++)
        digitalWrite(led[i], LOW);

      cekTombol();
      break;

    case 3: // Semua Kedip
      for(int i=0; i<8; i++)
        digitalWrite(led[i], HIGH);

      delay(200);

      for(int i=0; i<8; i++)
        digitalWrite(led[i], LOW);

      delay(200);

      cekTombol();
      break;
  }
}

void nyalakanSatu(int posisi) {

  for(int i=0; i<8; i++) {
    digitalWrite(led[i], LOW);
  }

  digitalWrite(led[posisi], HIGH);
  delay(100);
}

void cekTombol() {

  bool buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && lastButtonState == HIGH) {
    mode++;
    if(mode > 3) mode = 0;
    delay(200);
  }

  lastButtonState = buttonState;
}