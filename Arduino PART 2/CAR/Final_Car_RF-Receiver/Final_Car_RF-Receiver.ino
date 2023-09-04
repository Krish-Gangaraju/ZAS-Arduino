#include <SPI.h>
#include <RH_ASK.h>

const int rx_pin = 2; //used
const int tx_pin = 2; //not used
RH_ASK driver(2000, rx_pin, tx_pin, 0);

int LM1 = 7;
int LM2 = 8;
int RM1 = 11;
int RM2 = 10;

int speed1 = 3;
int speed2 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  analogWrite(speed1, 200);
  analogWrite(speed2, 200);
  
  Serial.begin(9600);

  if(!driver.init())
    Serial.println("init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  if(driver.recv(buf, &buflen))
  {
    Serial.print("Got:  ");
    for(int i = 0; i < buflen; i++)
    {
      Serial.println(char(buf[i]));
  if (buf[i] == "forward")
      forward();
    
  if (buf[i] == "back")
      back(); 
         
  if (buf[i] == "right")
      right();
    
  if (buf[i] == "left")
      left();

  if (buf[i] == "Stop")
      Stop();
 
 }
}
}
void forward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void back(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  void Stop(){ 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 

  }

  void left(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
