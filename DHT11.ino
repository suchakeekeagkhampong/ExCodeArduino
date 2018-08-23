#include <DHT.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define DHTPIN D2     // what digital pin we're connected to D4
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321  
DHT dht(DHTPIN, DHTTYPE);

  void setup()  {
      lcd.begin(D3, D4);
  lcd.backlight();
    Serial.begin(115200);
  }
  
  void loop()  {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  lcd.clear();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.home();
    lcd.print("Failed to read from DHT sensor!");
    return;
  }

  // show in serial monitor
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C \n");
  lcd.home();
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:"); 
  lcd.print(t);
  lcd.print("C");
  delay(500);
  }
