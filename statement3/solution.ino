// C++ code
//
#define trigpin 12
#define echopin 12
#define motor1 3
#define motor2 5
float duration, distance, speed;
void setup()
{
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop()
{
  pinMode(trigpin, OUTPUT);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  pinMode(echopin, INPUT);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)*0.0343;
  Serial.println(distance);
  if(distance > 336)
    speed = 255;
  else if (distance < 20)
    speed = 0;
  else
    speed = (255.0/316.0)*(distance - 20);
  analogWrite(motor1, speed);
  analogWrite(motor2, speed);
  delay(100);
}
