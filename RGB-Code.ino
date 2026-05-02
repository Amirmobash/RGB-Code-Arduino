const byte RED_PIN = 11;
const byte GREEN_PIN = 9;
const byte BLUE_PIN = 5;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  fadeColors(2);
  fadeColors(2);
  fadeColors(2);

  flashColors(300);
  flashColors(300);
  flashColors(300);

  fadeColors(10);

  flashColors(100);
  flashColors(100);
  flashColors(100);
  flashColors(100);
  flashColors(100);
}

void flashColors(int waitTime) {
  setRgbColor(255, 255, 255);
  delay(waitTime);

  setRgbColor(0, 255, 255);
  delay(waitTime);

  setRgbColor(255, 0, 255);
  delay(waitTime);

  setRgbColor(255, 255, 0);
  delay(waitTime);

  setRgbColor(0, 0, 255);
  delay(waitTime);

  setRgbColor(0, 255, 0);
  delay(waitTime);

  setRgbColor(255, 0, 0);
  delay(waitTime);
}

void fadeColors(int waitTime) {
  int redValue = 255;
  int greenValue = 0;
  int blueValue = 0;

  while (blueValue < 255) {
    blueValue++;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime * 3);
  }

  while (redValue > 0) {
    redValue--;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime * 2);
  }

  while (greenValue < 255) {
    greenValue++;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime);
  }

  while (blueValue > 0) {
    blueValue--;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime);
  }

  while (redValue < 255) {
    redValue++;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime * 2);
  }

  while (greenValue > 0) {
    greenValue--;
    setRgbColor(redValue, greenValue, blueValue);
    delay(waitTime * 3);
  }
}

void turnOffLed() {
  setRgbColor(0, 0, 0);
}

void setRgbColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RED_PIN, keepInRange(redValue));
  analogWrite(GREEN_PIN, keepInRange(greenValue));
  analogWrite(BLUE_PIN, keepInRange(blueValue));
}

int keepInRange(int value) {
  if (value < 0) return 0;
  if (value > 255) return 255;
  return value;
}
