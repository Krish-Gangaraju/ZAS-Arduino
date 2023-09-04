#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "V3DRFVP9bw9EjZO3j5CgdUbg7YryJB7e";
char ssid[] = "ZAS_G";
char pass[] = "SanaZara123";

BLYNK_WRITE(V1){
  int pinValue = param.asInt(); 
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
  if (pinValue == 1){
    ledon();
  }
  else if (pinValue == 0){
    ledoff();
  }
}

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); 
  pinMode(D3, OUTPUT); 
}
void loop(){
  Blynk.run();
}

void ledon(){
  digitalWrite(D3,HIGH);
}
void ledoff(){
  digitalWrite(D3,LOW);
}
