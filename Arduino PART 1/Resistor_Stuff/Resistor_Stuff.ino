
int light = A2;
int lvalue;
int led = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(light, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  lvalue = analogRead(light);
  Serial.println(lvalue);

  if(lvalue > 200)
    digitalWrite (led, HIGH);  
  else 
  digitalWrite(led,LOW);
  
  delay(1000);
}
