char t;

void setup() {
  pinMode(13, OUTPUT);  //left motors forward
  pinMode(12, OUTPUT);  //left motors reverse
  pinMode(11, OUTPUT);  //right motors forward
  pinMode(10, OUTPUT);  //right motors reverse
  pinMode(9, OUTPUT);  //Led
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {          //move forward(all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  }

  else if (t == 'B') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  }

  else if (t == 'L') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(13, HIGH);
  }

  else if (t == 'R') {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(11, HIGH);
  }

  else if (t == 'W') {  //turn led on or off)
    digitalWrite(9, HIGH);
  }
  else if (t == 'w') {
    digitalWrite(9, LOW);
  }
  else if (t == 'I') {
    analogWrite(11, 200);
    analogWrite(13, 100);
  }
  else if (t == 'G') {
    analogWrite(13, 200);
    analogWrite(11, 100);
  }
  else if (t == 'J') {
    analogWrite(12, 200);
    analogWrite(10, 100);
  }
  else if (t == 'H') {
    analogWrite(10, 200);
    analogWrite(12, 100);
  }
  else if (t == 'S') {    //STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  delay(10);
}
