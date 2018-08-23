//LED&Swicth2&LCD
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int sw1State = 0;
int sw2State = 0;
#define sw1 D0
#define sw2 D1
#define led1 D2
#define led2 D3
#define led3 D4
#define led4 D7
LiquidCrystal_I2C lcd(0x3F, 16, 2);
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0xe, 0x4, 0x0};

void setup() {
  Serial.begin(115200);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  lcd.begin(D5, D6);
  lcd.backlight();
  lcd.createChar(1, heart);

}

void loop() {
  sw1State = digitalRead(sw1);
  sw2State = digitalRead(sw2);

  if (sw1State == LOW) {
    lcd.home();
    lcd.print("Yallow Switch ");
    lcd.setCursor(0, 1);
    lcd.print("Right to Left");
    delay(500);
    lcd.setCursor(6, 1);
    lcd.print("->");
    sw1_open();
  } else if (sw2State == LOW) {
    lcd.home();
    lcd.print("Green Switch  ");
    lcd.setCursor(0, 1);
    lcd.print("Right back Left");
    delay(500);
    lcd.setCursor(6, 1);
    lcd.print(" <-  Left");
    sw2_open();
  } else {
    lcd.home();
    lcd.print("ALL Switch OFF");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
  /*lcd.home();
    lcd.print("Smart Farm IOT");
    lcd.setCursor(0, 1);
    lcd.print("Muchroom");
    delay(500);
    lcd.setCursor(12, 0);
    lcd.write(byte(1));
    delay(500);
    lcd.setCursor(12, 0);
    lcd.print(" ");*/

}
void sw1_open() {
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  delay(100);
}
void sw2_open() {
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
  delay(100);
    digitalWrite(led1, LOW);
  delay(100);
}


