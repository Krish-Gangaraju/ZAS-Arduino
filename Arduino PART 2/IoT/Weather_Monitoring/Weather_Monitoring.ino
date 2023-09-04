#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "I97gub338zDpqs6oJ5pWCTEvn4kdunba";
char ssid[] = "ZAS_G";
char pass[] = "SanaZara123";

#define DHTPIN D3          
#define sensor A0
#define DHTTYPE DHT11     

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  int gasLevel = analogRead(sensor);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V7, gasLevel);

  if(t>28){
    Blynk.email("krishuscan@gmail.com", "Temperature Alert", "Temperature over 28");
    Blynk.notify("Temperature over 28C");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
