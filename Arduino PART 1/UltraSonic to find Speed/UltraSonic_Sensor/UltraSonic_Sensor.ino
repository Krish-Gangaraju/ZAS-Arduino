#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int Trig = 7;
int Echo = 5;

float EchoTime;
float SoundSpeed;

long double EchoTimeSecs;
float DistanceMeters;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
  digitalWrite(Trig,LOW);
  delayMicroseconds(2),

  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);

  EchoTime = pulseIn(Echo,HIGH);
  EchoTimeSecs = EchoTime/1000000.0;
  Serial.println(EchoTime);
  //Serial.println(EchoTimeSecs);
  DistanceMeters  = 10/100.0;
  Serial.println(DistanceMeters);
  SoundSpeed  = (DistanceMeters*2)/(EchoTimeSecs);

  Serial.print("Speed:");
  Serial.println(SoundSpeed);
  
  display.println("Speed :");
  display.println(SoundSpeed);
  display.display();
  delay(100);

}
