//Exemple >> VR&LED&LCD
#include <LiquidCrystal_I2C.h>
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
//const int analogOutPin = 4; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int ledPin[] = {4, 0, 2};
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  for (int i = 0; i <= 2; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  lcd.begin(D5, D6);
  lcd.backlight();
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);
  
  for (int i = 0; i <= 2; i++) {
    analogWrite(ledPin[i], sensorValue);
  }
  /*close_led();
  if(sensorValue>=751){
    analogWrite(ledPin[0], 1024);
  }else if(sensorValue>=376){
    analogWrite(ledPin[1], 1024);
  }else{
    analogWrite(ledPin[2], 1024);
  }*/
  serial_print();
  cle();
  lcd_print();
  delay(100);
}
void cle() {
  lcd.home();
  lcd.print("sensor =    ");
  lcd.setCursor(0, 1);
  lcd.print("output =    ");
}
void serial_print(){
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
}
void lcd_print(){
  lcd.home();
  lcd.print("sensor =");
  lcd.print(sensorValue);
  lcd.setCursor(0, 1);
  lcd.print("output =");
  lcd.print(outputValue);
}
void close_led(){
  analogWrite(ledPin[0], 0);
  analogWrite(ledPin[1], 0);
  analogWrite(ledPin[2], 0);
}

