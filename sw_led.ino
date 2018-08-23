#define sw1 D0
#define sw2 D1
int sw1State = 0;
int sw2State = 0;
int openn = 0;


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  for (int i = 12; i <= 15; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  sw1State = digitalRead(sw1);
  sw2State = digitalRead(sw2);


  ch_sw(sw1State);

  open_led();

  /* else if(
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if(sw1State == LOW && sw2State == HIGH ) {
     ltor();

    } else if(sw1State == HIGH && sw2State == LOW ){
    rtol();

    } else {
     ledOff();
    }*/
}

void ch_sw(int sw1State) {
  if (sw1State == 0 && openn == 0) {
    openn++;
    delay(100);
  }
  else if (sw1State == 0 && openn == 1) {
    openn--;
    delay(100);
  }
}

void open_led() {
  if (openn == 1) {
    for (int i = 12; i <= 15; i++) {
      digitalWrite(i, HIGH);
      delay(100);
    }
    Serial.println("ON");
  } else if (openn == 0) {
    for (int i = 12; i <= 15; i++) {
      digitalWrite(i, LOW);
      delay(100);
    }
    Serial.println("OFF");
  }
}

void ltor() {
  for (int i = 12; i <= 15; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void rtol() {
  for (int i = 15; i >= 12; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void ledOff() {
  for (int i = 12; i <= 15; i++) {
    digitalWrite(i, LOW);
  }
}
