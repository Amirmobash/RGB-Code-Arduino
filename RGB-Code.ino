const byte rotPin = 11;
const byte gruenPin = 9;
const byte blauPin = 5;

void setup() {
  pinMode(rotPin, OUTPUT);
  pinMode(gruenPin, OUTPUT);
  pinMode(blauPin, OUTPUT);
}

void loop() {
  uebergang(2);
  uebergang(2);
  uebergang(2);

  schnellWechsel(300);
  schnellWechsel(300);
  schnellWechsel(300);

  uebergang(10);

  schnellWechsel(100);
  schnellWechsel(100);
  schnellWechsel(100);
  schnellWechsel(100);
  schnellWechsel(100);
}

void allesAus() {
  farbeSetzen(0, 0, 0);
}

void schnellWechsel(int pause) {
  farbeSetzen(255, 255, 255);
  delay(pause);

  farbeSetzen(0, 255, 255);
  delay(pause);

  farbeSetzen(255, 0, 255);
  delay(pause);

  farbeSetzen(255, 255, 0);
  delay(pause);

  farbeSetzen(0, 0, 255);
  delay(pause);

  farbeSetzen(0, 255, 0);
  delay(pause);

  farbeSetzen(255, 0, 0);
  delay(pause);
}

void uebergang(int pause) {
  int rot = 255;
  int gruen = 0;
  int blau = 0;

  while (blau < 255) {
    blau++;
    farbeSetzen(rot, gruen, blau);
    delay(pause * 3);
  }

  while (rot > 0) {
    rot--;
    farbeSetzen(rot, gruen, blau);
    delay(pause * 2);
  }

  while (gruen < 255) {
    gruen++;
    farbeSetzen(rot, gruen, blau);
    delay(pause);
  }

  while (blau > 0) {
    blau--;
    farbeSetzen(rot, gruen, blau);
    delay(pause);
  }

  while (rot < 255) {
    rot++;
    farbeSetzen(rot, gruen, blau);
    delay(pause * 2);
  }

  while (gruen > 0) {
    gruen--;
    farbeSetzen(rot, gruen, blau);
    delay(pause * 3);
  }
}

void farbeSetzen(int rot, int gruen, int blau) {
  analogWrite(rotPin, begrenzen(rot));
  analogWrite(gruenPin, begrenzen(gruen));
  analogWrite(blauPin, begrenzen(blau));
}

int begrenzen(int wert) {
  if (wert < 0) return 0;
  if (wert > 255) return 255;
  return wert;
}
