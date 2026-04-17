/*
  RGB-LED Effektcode
  Erstellt / verbessert für: Amir Mobasher
*/

const byte ROT_PIN   = 11;
const byte GRUEN_PIN = 9;
const byte BLAU_PIN  = 5;

void setup() {
  pinMode(ROT_PIN, OUTPUT);
  pinMode(GRUEN_PIN, OUTPUT);
  pinMode(BLAU_PIN, OUTPUT);
}

void loop() {
  // Unterschiedliche Delays sorgen für schnelle und langsame Effekte
  fade(2);
  fade(2);
  fade(2);

  stroboskop(300);
  stroboskop(300);
  stroboskop(300);

  fade(10);

  stroboskop(100);
  stroboskop(100);
  stroboskop(100);
  stroboskop(100);
  stroboskop(100);
}

// Schaltet alle Farben aus
void aus() {
  setzeRot(0);
  setzeGruen(0);
  setzeBlau(0);
}

// Schneller Farbwechsel / Stroboskop-Effekt
void stroboskop(int verzogerung) {
  zeigeRGB(255, 255, 255); // Weiß
  delay(verzogerung);

  zeigeRGB(0, 255, 255);   // Cyan
  delay(verzogerung);

  zeigeRGB(255, 0, 255);   // Lila
  delay(verzogerung);

  zeigeRGB(255, 255, 0);   // Gelb
  delay(verzogerung);

  zeigeRGB(0, 0, 255);     // Blau
  delay(verzogerung);

  zeigeRGB(0, 255, 0);     // Grün
  delay(verzogerung);

  zeigeRGB(255, 0, 0);     // Rot
  delay(verzogerung);
}

// Sanfter Übergang zwischen den Farben
void fade(int verzogerung) {
  int r = 255;
  int g = 0;
  int b = 0;

  for (; b <= 255; b++) {
    zeigeRGB(r, g, b);
    delay(verzogerung * 3);
    // Rot wirkt optisch oft dunkler, daher längere Verzögerung
  }

  for (; r >= 0; r--) {
    zeigeRGB(r, g, b);
    delay(verzogerung * 2);
  }

  for (; g <= 255; g++) {
    zeigeRGB(r, g, b);
    delay(verzogerung);
  }

  for (; b >= 0; b--) {
    zeigeRGB(r, g, b);
    delay(verzogerung);
  }

  for (; r <= 255; r++) {
    zeigeRGB(r, g, b);
    delay(verzogerung * 2);
  }

  for (; g >= 0; g--) {
    zeigeRGB(r, g, b);
    delay(verzogerung * 3);
  }
}

// Zeigt eine RGB-Farbe an
void zeigeRGB(int r, int g, int b) {
  setzeRot(r);
  setzeGruen(g);
  setzeBlau(b);
}

// Setzt die rote Helligkeit
void setzeRot(int wert) {
  if (wert >= 0 && wert <= 255) {
    analogWrite(ROT_PIN, wert);
  }
}

// Setzt die grüne Helligkeit
void setzeGruen(int wert) {
  if (wert >= 0 && wert <= 255) {
    analogWrite(GRUEN_PIN, wert);
  }
}

// Setzt die blaue Helligkeit
void setzeBlau(int wert) {
  if (wert >= 0 && wert <= 255) {
    analogWrite(BLAU_PIN, wert);
  }
}
