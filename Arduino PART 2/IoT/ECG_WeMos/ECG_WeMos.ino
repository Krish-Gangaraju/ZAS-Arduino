#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int Signal;
int PulseSensorPin = A0;

char auth[] = "b7BGQGJVb1oeqTJE2DS8hX9Qfk3rBvdP";
char ssid[] = "ZAS_G";
char pass[] = "SanaZara123";
BlynkTimer timer;

void sendSensor()
{
  Signal = analogRead(PulseSensorPin);

   if((digitalRead(D3) == 1)||(digitalRead(D2) == 1)){
    Serial.println('!');
  }
  else{
      Serial.println(Signal);
      Blynk.virtualWrite(V5, Signal);
}
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D3, INPUT); //  LO +
  pinMode(D2, INPUT); //  LO -
  pinMode(PulseSensorPin, INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(0.1L, sendSensor);

}
void loop()
{
  Blynk.run();
  timer.run();

}
