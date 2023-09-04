#include <IRremote.h>
int IRpin = 12;

int LM1 = 7;
int LM2 = 8;
int RM1 = 10;
int RM2 = 11;

int speed1 = 3;
int speed2 = 6;

IRrecv irrecv(IRpin);
decode_results results;

void setup() {
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  analogWrite(speed1, 255);
  analogWrite(speed2, 255);
  
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
 
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, DEC);
    irrecv.resume();
  }
  if (results.value == 12583000)//UP (forward)
  {
    forward();    
  }
  else if (results.value == 12583001)//DOWN (back)
  {
    back();
  }
  else if (results.value == 12583004)//CENTER (stop)
  {
    Stop();
  }
  else if (results.value == 12583002)//LEFT
  {
     left();
  }
  else if (results.value == 12583003)//RIGHT
  {
     right();
  }
  
}
 
  void right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void left(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  void Stop(){ 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 

  }

  void back(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void forward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
