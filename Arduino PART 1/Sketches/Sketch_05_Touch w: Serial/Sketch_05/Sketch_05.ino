int Buzzer = 10;
int SensorPin = 2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(SensorPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = digitalRead(SensorPin);

  if(sensorValue == HIGH)
   {
      Serial.println("TOUCHED");
      digitalWrite(Buzzer, HIGH);
    }
   else
      {
        Serial.println("NOT TOUCHED");
        digitalWrite(Buzzer, LOW);
          }
          
  delay(1000);
          
}
