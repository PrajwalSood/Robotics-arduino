int ledPin=9; // definition digital 8 pins as pin to control the LED
void setup() 
{
  pinMode(ledPin,OUTPUT); //Set digital 8 port mode, OUTPUT; Output mode
}
void loop() 
{
  for (int i=0; i<256; i++)
  {
    delay(10);
  analogWrite(ledPin,i);
  }
  for (int i=0; i<256; i++)
  
  {
    delay(10);
  analogWrite(ledPin,255-i);
  }
  
}
