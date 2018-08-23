int frequency=1000; //Specified in Hz
int buzzPin=16; 
int timeOn=500; //specified in milliseconds
int timeOff=2000; //specified in millisecods

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzPin, frequency);
  delay(timeOn);
  noTone(buzzPin);
  delay(timeOff);
}
