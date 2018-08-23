#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//blink left to right and Right to left control by SW1 and SW2
//Power by Mr.Pornchai
#define sw1 D0
#define sw2 D1
#define scl D3
#define sda D4
int sw1State = 0;
int sw2State = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ///Serial.println("Test");
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(scl,OUTPUT);
  pinMode(sda,OUTPUT);
  for (int i = 12; i <= 15; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  sw1State = digitalRead(sw1);
  sw2State = digitalRead(sw2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (sw1State == LOW && sw2State == HIGH ) {
    ltor();
    Serial.println("Sw 1 On");

  } else if (sw1State == HIGH && sw2State == LOW ) {
    rtol();
    Serial.println("Sw 2 On");
  } else if (sw1State == LOW && sw2State == LOW) {
    Serial.println("All On");
  } else {
    ledOff();
    Serial.println("All Off");
  }
  delay(500);
}

void ltor() {
  for (int i = 12; i <= 15; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void rtol() {
  for (int i = 15; i >= 12; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void ledOff() {
  for (int i = 12; i <= 15; i++) {
    digitalWrite(i, LOW);
  }
}
