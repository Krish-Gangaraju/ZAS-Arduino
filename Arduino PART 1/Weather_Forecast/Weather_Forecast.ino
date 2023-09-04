#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
Adafruit_BMP280 bmp;

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define gasSensor A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  dht.begin();
  bmp.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float temp = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float gasLevel = analogRead(gasSensor);

  Serial.print("Pressure: ");
  Serial.println(pressure);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Temperature BMP: ");
  Serial.println(temp);

  Serial.print("Gas Level: ");
  Serial.println(gasLevel);
  Serial.println(" ");

  delay(1000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print ("Temp : ");
  display.println(temperature);
  display.print("Humidity : ");
  display.println(humidity);
  display.print("Gas : ");
  display.println(gasLevel);
  display.print("Pressure : ");
  display.println(pressure);
  display.display();

}
