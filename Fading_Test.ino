int ledPin3 = 3;
int ledPin5 = 5;
int ledPin6 = 6;
int ledPin9 = 9;

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin9, OUTPUT);
}
void fadeLED6() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin6, fadeValue);
    delay(30);
  }
  timel3();
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin6, fadeValue);
    delay(30);
  }
}

void fadeLED9() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin9, fadeValue);
    delay(30);
  }
  timel3();
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin9, fadeValue);
    delay(30);
  }
}

void fadeLED3() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin3, fadeValue);
    delay(30);
  }
  timel3();
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin3, fadeValue);
    delay(30);
  }
}

void fadeLED5() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin5, fadeValue);
    delay(30);
  }
  timel3();
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin5, fadeValue);
    delay(30);
  }
}

void timel3() {
  delay(2000);
}

void loop() {
  fadeLED3();
  fadeLED5();
  fadeLED6();
  fadeLED9();
}
