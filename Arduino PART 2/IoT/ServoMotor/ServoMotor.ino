#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>


char auth[] = "qtjICFBmwX7Dgr-v0e-bOVyw8GGjIsOd";
char ssid[] = "ZAS_G";
char pass[] = "SanaZara123";

Servo servo;

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D3);
}

void loop()
{
  Blynk.run();
}
