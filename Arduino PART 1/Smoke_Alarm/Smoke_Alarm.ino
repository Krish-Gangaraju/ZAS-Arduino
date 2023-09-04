#include <Adafruit_SSD1306.h>
#define sensor A0
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int led = 11;
int gasLevel = 1;
int Buzzer = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(sensor, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);

  

  gasLevel = analogRead(sensor);
  Serial.println("GasLevel: ");
  Serial.println(gasLevel);

  display.println("Gas Level: ");
  display.println(gasLevel);
  display.print("ppm");
  display.display();

  if (gasLevel>150)
  {
    display.println("Gas Level is too high");
    display.display();
    digitalWrite(Buzzer, HIGH);
    digitalWrite(led, HIGH);
  }
  else
    digitalWrite(Buzzer, LOW);
    digitalWrite(led, LOW);
    
  delay(1500);
 

}
