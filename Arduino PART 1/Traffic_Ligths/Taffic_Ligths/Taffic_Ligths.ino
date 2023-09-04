int Red = 2;
int Green = 11;
int Yellow = 7;

void setup() {
  // put your setup code here, to run once:

pinMode(Red, OUTPUT);
pinMode(Yellow, OUTPUT);
pinMode(Green, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(Red, HIGH);
digitalWrite(Yellow, LOW);
digitalWrite(Green, LOW);
delay(4000);
digitalWrite(Red, LOW);
digitalWrite(Yellow, HIGH);
digitalWrite(Green, LOW);
delay(1000);
digitalWrite(Red, LOW);
digitalWrite(Yellow, LOW);
digitalWrite(Green, HIGH);
delay(4000);

}
