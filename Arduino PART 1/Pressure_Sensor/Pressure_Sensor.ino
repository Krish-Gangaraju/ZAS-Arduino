#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bmp.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println("degrees Celsius");

  Serial.print("Atmospheric Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println("Pa");

  Serial.print("Approx Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println("m");

  Serial.println();
  delay(2500);



}
