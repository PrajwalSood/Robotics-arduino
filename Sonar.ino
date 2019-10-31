const int trigpin = 12; 
const int echopin = 11;
const int l = 13;
const int l1 = 8;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

}

void loop() {
  long duration, inches, cm;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.println();
  delay(100);
  if (cm < 5){
    digitalWrite(l, HIGH);
    delayMicroseconds(10000000000000000);
    digitalWrite(l, LOW);
  }
  else if (cm < 10){
    digitalWrite(l1, HIGH);
    delayMicroseconds(100000000000000000);
    digitalWrite(l1, LOW);
  }
   else{
    digitalWrite(l, HIGH);
    delayMicroseconds(10000000000000000);
    digitalWrite(l, LOW);
    digitalWrite(l1, HIGH);
    delayMicroseconds(1000000000000000000);
    digitalWrite(l1, LOW);
   
  }
}

long microsecondsToInches(long microseconds){
  return microseconds/74/2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}
