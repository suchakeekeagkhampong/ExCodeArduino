#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#define rainPin A0
#define greenLED D0
#define redLED D1

int threshoIdValue = 900;
void setup() {
  lcd.begin(D3, D4);
  lcd.backlight();
  pinMode(rainPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(greenLED, 1);
  digitalWrite(redLED, 1);
}

void loop() {
  int sensorValue = analogRead(rainPin);
  Serial.println(sensorValue);
  lcd.clear();
  if (sensorValue > threshoIdValue) {
    Serial.println("need water");
    digitalWrite(greenLED, 1);
    digitalWrite(redLED, 0);
    lcd.home();
    lcd.print("Moisture = ");
    lcd.print(sensorValue);
    lcd.setCursor(0, 1);
    lcd.print("need water");
  } else {
    Serial.println("NO");
    digitalWrite(greenLED, 0);
    digitalWrite(redLED, 1);
    lcd.home();
    lcd.print("Moisture = ");
    lcd.print(sensorValue);
    lcd.setCursor(0, 1);
    lcd.print("don't need water");
  }
  delay(500);
}
