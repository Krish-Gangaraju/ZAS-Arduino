#include <IRremote.h>

int IR = 11;
int light = 2;
int buzz = 3;
IRrecv irrecv(IR);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(light,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, DEC);
    irrecv.resume();
  }
  if (results.value == 2704)//ON
  {
    digitalWrite(light, HIGH);
    
  }
  else if (results.value == 2320)//0
  {
    digitalWrite(buzz, HIGH);
   
  }
  else if (results.value == 2672)//center
  {
    digitalWrite(light, LOW);
    digitalWrite(buzz, LOW);
    
  }
}
