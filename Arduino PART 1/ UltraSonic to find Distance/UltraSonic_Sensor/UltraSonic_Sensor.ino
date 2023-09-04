#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int Echo = 7;
int Trig = 6;
int buzzer = 10;
int led = 2;

float Distance;
float EchoTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(2,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
   
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
   
  EchoTime = pulseIn(Echo,HIGH);
  Distance = (EchoTime/2)*(0.034);

  Serial.print("Distance:");
  Serial.println(Distance);
  
  display.println("Distance :");
  display.println(Distance);
  display.display();
  delay(100);

  if (Distance > 20){
    digitalWrite(2,HIGH);
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(2,LOW);
    digitalWrite(10,LOW);
  }
  delay(1500);
}
