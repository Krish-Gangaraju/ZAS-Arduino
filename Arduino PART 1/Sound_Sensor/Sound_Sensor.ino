int SoundPin = A7;
int led = 2;
int buzz = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(2,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Value = digitalRead(SoundPin);
  Serial.print(Value);
  Serial.println("Hz");

  if (Value == 1)
    {
      digitalWrite(led, HIGH);
      digitalWrite(buzz,HIGH);
    }
  else {
    digitalWrite(led,LOW);
    digitalWrite(buzz,LOW);
  }

  delay(150);

}
