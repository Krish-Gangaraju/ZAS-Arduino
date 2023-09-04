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

if (joyValuex == 58 && joyValuex == 0){
const char *msg = "forward";
driver.send (msg, strlen(msg));
driver.waitPacketSent();
Serial.println(msg);
}

else if (joyValuex == 58 && joyValuex == 118){
const char *msg = "back";
driver.send (msg, strlen(msg));
driver.waitPacketSent();
Serial.println(msg);
}

if (joyValuex == 0 && joyValuex == 58){
const char *msg = "right";
driver.send (msg, strlen(msg));
driver.waitPacketSent();
Serial.println(msg);
}

else if (joyValuex == 118 && joyValuex == 58){
const char *msg = "left";
driver.send (msg, strlen(msg));
driver.waitPacketSent();
Serial.println(msg);
}

else if (joyValuey == 58 && joyValuex == 58){
const char *msg = "Stop";
driver.send (msg, strlen(msg));
driver.waitPacketSent();
Serial.println(msg );
}

}
