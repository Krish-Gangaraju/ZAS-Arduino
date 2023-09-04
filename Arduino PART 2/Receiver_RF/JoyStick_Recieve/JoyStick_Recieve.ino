#include <SPI.h>
#include <RH_ASK.h>

int led = 3;
int ledb = 4;

const int rx_pin = 2; //used
const int tx_pin = 2; //not used

RH_ASK driver(2000, rx_pin, tx_pin, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ledb, OUTPUT);

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
  if (buf[i] == 'a')
      digitalWrite(led, HIGH);
    
  if (buf[i] == 'b')
      digitalWrite(led, LOW);
    
  if (buf[i] == 'c')
      digitalWrite(ledb, HIGH);
    
  if (buf[i] == 'd')
      digitalWrite(ledb, LOW);
 }
}
}
