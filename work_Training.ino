const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

int enA = 3;
int in1 = 4;
int in2 = 5;

int enB = 11;
int in3 = 6;
int in4 = 7;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void moveforWard() {
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void movebackWard() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 120);
}

void moveStop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void moveturnRigt() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void moveturnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

int lookRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(500);
  int distance = readPing();
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(500);
  return distance;
}

int lookLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(500);
  int distance = readPing();
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(500);
  return distance;
}

int readPing() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}

void loop() {
  int  distanceR = 0;
  int  distanceL = 0;

  readPing();
  if (distance <= 15) {
    moveStop();
    delay(100);
    movebackWard();
    delay(100);
    distanceR = lookRight();
    delay(100);
    distanceL = lookLeft();
    delay(100);
    if (distanceR >= distanceL) {
      moveturnRigt();
      moveStop();
    } else {
      moveturnLeft();
      moveStop();
    }
  } else {
    moveforWard();
  }
  distance = readPing();
}
