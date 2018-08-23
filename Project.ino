
#define swBlue 3
int status = false;

const int trigPin = 4;
const int echoPin = 5;
long duration;
int distance;

void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(50);
}
void setup() {
  pinMode(2 , OUTPUT); //relay
  pinMode(swBlue , INPUT_PULLUP); //switch button
  pinMode(trigPin, OUTPUT); // trigPin Output
  pinMode(echoPin, INPUT); // echoPin Input
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(swBlue) == true) {
    status = !status;
    digitalWrite(2, status);
  } while (digitalRead(swBlue) == true);

}

