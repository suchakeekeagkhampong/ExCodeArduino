// the setup function runs once when you press reset or power the board
int led_output5 = 5;
int led_output14 = 14;
int led_output12 = 12;
int led_output4 = 4;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led_output5, OUTPUT);
  pinMode(led_output4, OUTPUT);
  pinMode(led_output14, OUTPUT);
  pinMode(led_output12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {  
  digitalWrite(led_output5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(led_output5, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
   digitalWrite(led_output12, HIGH);  
  delay(100);                       
  digitalWrite(led_output12, LOW);   
  delay(100);   
  digitalWrite(led_output14, HIGH);  
  delay(100);                       
  digitalWrite(led_output14, LOW);   
  delay(100);
  digitalWrite(led_output4, HIGH);  
  delay(100);                       
  digitalWrite(led_output4, LOW);   
  delay(100);                                
}
