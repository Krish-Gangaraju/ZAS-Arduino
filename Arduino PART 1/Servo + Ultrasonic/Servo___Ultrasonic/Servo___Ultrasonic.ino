#include <Servo.h>
Servo servo;

int Echo = 7;
int Trig = 6;
int angle = 0;

float Distance;
float EchoTime;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  
  servo.attach(3);
  servo.write(angle);
  delay(2000);
}

void loop()
{
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
   
  EchoTime = pulseIn(Echo,HIGH);
  Distance = (EchoTime/2)*(0.034);

  Serial.print("Distance:");
  Serial.println(Distance);
delay(1000);

  if (Distance < 20)
  {
    servo.write(90);
    delay(1000);
    servo.write(0); 
  }
  else
 {
    servo.write(0);
 }
 delay(1000);
  }
