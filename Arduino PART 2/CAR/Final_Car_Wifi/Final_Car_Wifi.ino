#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "pXZlGeKQp8Eic4RgksjhKRHtyeW9q93f";
char ssid[] = "Realme C1";
char pass[] = "gkkraju28";

int LM1 = D3;
int LM2 = D4;
int RM1 = D5;
int RM2 = D6;
int speed1 = D8;
int speed2 = D9;

BLYNK_WRITE(V1){
  int FORWARD = param.asInt(); 
  Serial.print(FORWARD);
  if (FORWARD == 1){
    forward();
  }
}
BLYNK_WRITE(V2){
  int REVERSE = param.asInt(); 
  if (REVERSE == 1){
    back();
  }
}
BLYNK_WRITE(V3){
  int LEFT = param.asInt(); 
  if (LEFT == 1){
    left();
  }
}
BLYNK_WRITE(V4){
  int RIGHT = param.asInt(); 
  if (RIGHT == 1){
    right();
  }
} 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  analogWrite(speed1, 714);
  analogWrite(speed2, 714);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  
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

  void forward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void back(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
