// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char ch = Serial.read();
  if(ch == 'a')
  {
    dot();
    dash();
  }
  else if(ch == 'b')
  {
    dash();dot();dot();dot();
  }
  else if(ch == 'c')
  {
    dash();dot();dash();dot();
  }
}

void dot()
{
  digitalWrite(13, HIGH);
  delay(50); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void dash()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
