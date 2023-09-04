int Relay = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(Relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Relay,HIGH);
    delay(1000);
  digitalWrite(Relay,LOW);
    delay(1000);
}
