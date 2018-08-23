#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = D1; // Analog output pin that the LED is attached to
#define sw1 D0
bool sw1State = false;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
   pinMode(sw1, INPUT);
  lcd.begin(D3,D4); // In ESP8266-01, SDA=D3, SCL=D4
  lcd.backlight();
  pinMode(analogInPin,INPUT);
  pinMode(analogOutPin,OUTPUT);
  pinMode(D2,OUTPUT);
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  //sw1State = digitalRead(sw1);
   if (digitalRead(sw1) == LOW)
   sw1State =! sw1State;
   if (sw1State)
   digitalWrite(D2,0);
   else
   digitalWrite(D2,1);
   delay(200);
  // read the analog in value:
   sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);
  analogWrite(analogOutPin, sensorValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
  lcd.clear();
  lcd.home();
  lcd.print("sensor = ");
  //lcd.setCursor(0,1);.
  
  lcd.print(sensorValue);
 delay(0);
}
