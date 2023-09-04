#include <Adafruit_SSD1306.h>
#define sensor A0
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int gasLevel = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(sensor,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  gasLevel = analogRead(sensor);
  Serial.println(" Gas Level:");
  Serial.println(gasLevel);
delay(500);
  display.println("Gas Level:");
  display.println(gasLevel);
  display.display();




}
