
int Red = 2;


void setup() {
  // put your setup code here, to run once:

  pinMode(Red, OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:

  digitalWrite(Red, HIGH);
  delay(500);
  digitalWrite(Red, LOW);
  delay(500);

}
