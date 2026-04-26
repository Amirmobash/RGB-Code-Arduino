const byte redPin = 11;
const byte greenPin = 9;
const byte bluePin = 5;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  transition(2);
  transition(2);
  transition(2);

  quickChange(300);
  quickChange(300);
  quickChange(300);

  transition(10);

  quickChange(100);
  quickChange(100);
  quickChange(100);
  quickChange(100);
  quickChange(100);
}

void allOff() {
  setColor(0, 0, 0);
}

void quickChange(int pause) {
  setColor(255, 255, 255);
  delay(pause);

  setColor(0, 255, 255);
  delay(pause);

  setColor(255, 0, 255);
  delay(pause);

  setColor(255, 255, 0);
  delay(pause);

  setColor(0, 0, 255);
  delay(pause);

  setColor(0, 255, 0);
  delay(pause);

  setColor(255, 0, 0);
  delay(pause);
}

void transition(int pause) {
  int red = 255;
  int green = 0;
  int blue = 0;

  while (blue < 255) {
    blue++;
    setColor(red, green, blue);
    delay(pause * 3);
  }

  while (red > 0) {
    red--;
    setColor(red, green, blue);
    delay(pause * 2);
  }

  while (green < 255) {
    green++;
    setColor(red, green, blue);
    delay(pause);
  }

  while (blue > 0) {
    blue--;
    setColor(red, green, blue);
    delay(pause);
  }

  while (red < 255) {
    red++;
    setColor(red, green, blue);
    delay(pause * 2);
  }

  while (green > 0) {
    green--;
    setColor(red, green, blue);
    delay(pause * 3);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, limit(red));
  analogWrite(greenPin, limit(green));
  analogWrite(bluePin, limit(blue));
}

int limit(int value) {
  if (value < 0) return 0;
  if (value > 255) return 255;
  return value;
}
