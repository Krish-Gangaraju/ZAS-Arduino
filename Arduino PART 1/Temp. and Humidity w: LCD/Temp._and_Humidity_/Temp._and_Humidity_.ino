#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display (OLED_RESET);


#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin (SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();

  lcd.init();
  lcd.backlight();
}


void loop() {
  // put your main code here, to run repeatedly:

  float h = dht.readHumidity ();  //Reads temperature in C
  float t = dht.readTemperature(); 

  Serial.print("Humidity: ");
  Serial.println(h);

  Serial.println("Temperature: ");
  Serial.println(t);
  delay(5000);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    
    
  display.print("Humidity: ");
  display.println(h);
       display.display();
  display.print("Temperature: ");
  display.println(t);
      display.display();

  lcd.setCursor(0,0);
  lcd.print("Humidity: "); lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print ("TempC: ");lcd.print(t);

delay(5000);
} 
