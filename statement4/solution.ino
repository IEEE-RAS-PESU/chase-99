void setup()
{
  //flex 
  pinMode(A0, INPUT);
  //motor1 
  pinMode(11, OUTPUT); //en 2
  pinMode(3, OUTPUT);  //ip4
  pinMode(5, OUTPUT); //ip3
  
  //motor2
  pinMode(10, OUTPUT); //en 1 
  pinMode(4, OUTPUT); //ip2
  pinMode(7, OUTPUT); //ip1
}

void loop()
{
  int Flex = analogRead(A0);
  Serial.println(Flex);
  //forward
  if(Flex>85){
  //motor1
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  //speed control
  analogWrite(10, Flex);
  
  //motor2s
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  //speed control
  analogWrite(11, Flex);
  }
  
  //reverse
  if(Flex<85)
  {
    digitalWrite(7,LOW);
    digitalWrite(4,HIGH);
  //speed control
    analogWrite(10, Flex);
  
  //motor2s
    digitalWrite(5,LOW);
    digitalWrite(3,HIGH);
  //speed control
    analogWrite(11, Flex);    
  }
}
