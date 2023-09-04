#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "SaQIJpmQcm3SXnVDm3WFNjMrKR3e9FVh";
char ssid[] = "Gkiran";
char pass[] = "Gkkraju7";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
