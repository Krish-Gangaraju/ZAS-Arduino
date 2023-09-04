#include <SPI.h>
#include <RH_ASK.h>

const int rx_pin = 2; //used
const int tx_pin = 2; //not used

RH_ASK driver(2000, rx_pin, tx_pin, 0);

void setup() {
  Serial.begin(9600);
  if(!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if(driver.recv(buf, &buflen))
  {
    Serial.print("Got:  ");

    for(int i = 0; i < buflen; i++)
    {
      Serial.print(char(buf[i]));
      Serial.print(" ");
    }

    Serial.println(" ");
  }
}
