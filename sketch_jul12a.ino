
const int trigPin = 9;   //กำหนดชื่อตัวแปรสำหรับส่งสัญญาณออกไป
const int echoPin = 10;  //กำหนดชื่อตัวแปรรับสัญญาเสียงเข้ามา
long duration;
int distance;

// Motor A
int enA = 3;
int in1 = 4;
int in2 = 5;

// Motor B
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
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // ให้ขา 9 เป็นตัวเปิดส่งสัญญาเสียงออกไป
  pinMode(echoPin, INPUT);  // ให้ขา 10 เป็นตัวรับสัญญาเสียงเข้ามา

}

void forWard() {
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void backWard() {
  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void Stop() {
  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 0);
  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 0);
}

void turnRigt() {
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void turnLeft() {
  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void ultra() {
  distance = duration * 0.034 / 2;
  }

void loop() {
  long duration, cm;

  //pinMode(pingPin, OUTPUT);
  digitalWrite(trigPin, LOW);  //ปิดเสียง
  delayMicroseconds(2);        // เป็นเวลา 2 ไมโครวินาที หรือ 2 ในล้านวินาที
  digitalWrite(trigPin, HIGH); // เปิดเสียงอัลตราโซนิก
  delayMicroseconds(5);        // เป็นเวลา 5 ไมโครวินาที หรือ 5 ในล้านวินาที
  digitalWrite(trigPin, LOW);  // ปิดเสียงอัลตราโซนิก

  duration = pulseIn(echoPin, HIGH); //จับเวลาตั่งแต่ที่ปล่อยเสียงออกไปจนเสียงสะท้อนกลับมายังตัวรับ
  
  // แปลงจากเวลาที่จับได้ให้เป็นระยะทาง
  cm = duration();

  int leftDistance, rightDistance;
  
  if (inches <= 5 || cm <= 15) {
    Stop();
    delay(100);
    backWard();
    delay(300);
    Stop();
    delay(100);
    rightDistance = microseconds();
    delay(200);
    leftDistance = microseconds();
    delay(200);

    if(inches <= 5 || cm <= 15){
      
      }
  }
//    Serial.print(inches);                 // พิมพ์ค่าระยะทางออกทางจอภาพ
//    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
  }
