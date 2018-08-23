//LED&Switch&Relay&LCD
#include <LiquidCrystal_I2C.h>
#define sw D0
int status = false;
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(D5, D6);
  lcd.backlight();
  pinMode(2, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(sw) == true) {
    status = !status;
    digitalWrite(2, status);
  } while (digitalRead(sw) == true);

  if (status == true) {
    lcd.home();
    lcd.print("LED ON");
  } else {
    lcd.home();
    lcd.print("LED OFF");
  }
  delay(50);
}
