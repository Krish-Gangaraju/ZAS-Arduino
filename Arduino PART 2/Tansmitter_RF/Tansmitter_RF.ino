#include <RH_ASK.h>
#include <SPI.h>

const int tx = 2;
const int rx = 2;

RH_ASK driver (2000, rx, tx, 0);

void setup() {
  Serial.begin(9600);

  if (!driver.init()){
      Serial.println("initialisation failed");
    }
}

void loop() {
  const char *msg  = "hello there xD";

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200); 
}
