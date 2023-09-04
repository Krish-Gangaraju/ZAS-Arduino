#include "DHT.h"
#include <Adafruit_SSD1306.h>
#define sensor A0
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = 8;
int led2 = 5;
int gasLevel = 1;
int Buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  pinMode(sensor, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);

   float h = dht.readHumidity();
   float t = dht.readTemperature();
  display.print("Humidity: ");
  display.println(h);
       display.display();
  display.print("Temperature: ");
  display.println(t);
      display.display();

   if (h > 35) {
    digitalWrite(led2, HIGH);
   }
   else{
    digitalWrite(led2, LOW);
   }
   delay(1500);
   
  gasLevel = analogRead(sensor);
  Serial.println("GasLevel: ");
  Serial.println(gasLevel);

  display.println("Gas Level: ");
  display.println(gasLevel);
  display.display();
  
  if (gasLevel>150){
    digitalWrite(led, HIGH);
    digitalWrite(Buzzer, HIGH);
  }
  else
    digitalWrite(led, LOW);
    digitalWrite(Buzzer, LOW);
  delay(1500);
}
