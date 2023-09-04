#include <RH_ASK.h>
#include <SPI.h>

const int rx_pin = 2;
const int tx_pin = 2;
RH_ASK driver(2000, rx_pin, tx_pin, 0);

void setup() {
Serial.begin(9600);
if(!driver.init())
Serial.println("init failed");
}

void loop() {

int joyValuex = analogRead(A0);
int joyValuey = analogRead(A1);
int degree = map(joyValuex,0,1023,0,180);
int degree2 = map(joyValuey,0,1023,0,180);

if (joyValuex > 1015)
{const char *msg = "a";
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
}


else if (joyValuex < 10)
{const char *msg = "b";
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();}


if (joyValuey > 1015)
{const char *msg = "c";
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();}


else if (joyValuey < 10)
{const char *msg = "d";
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();}


}
