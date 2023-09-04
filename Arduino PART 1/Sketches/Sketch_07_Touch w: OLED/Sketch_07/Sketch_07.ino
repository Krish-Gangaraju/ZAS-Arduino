
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
  int ledPin = 5;
  int sensorPin = 4;
  int buzzer = 10;
  
void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    pinMode(ledPin, OUTPUT);
    pinMode(sensorPin, INPUT);
    pinMode(buzzer, OUTPUT);
    display.print("Anything");
}

void loop() {
  // put your main code here, to run repeatedly:
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);

  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == HIGH){
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin, HIGH);
      Serial.print("TOUCHED");
      display.print("TOUCHED");
      display.display(); 
    
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    Serial.print("NOT TOUCHED");

    display.print("NOT TOUCHED");
    display.display();
  }

    delay(1000);
}      
