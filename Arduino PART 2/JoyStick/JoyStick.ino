
int led = 3;
int ledb = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ledb, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 
  int joyx = analogRead(A0);
  int joyy = analogRead(A1);
 int anglex = map(joyx, 0, 1023, 0, 180);
 int angley = map(joyy, 0, 1023, 0, 180);

  if (anglex > 90){
    digitalWrite(led, HIGH);
    digitalWrite(ledb, HIGH);
    delay(200);
  }
  else if (angley > 90){
    digitalWrite(led, HIGH);
    digitalWrite(ledb, HIGH);
    delay(200);
  }
  else if (angley == 90 && anglex == 90){
    digitalWrite(led, LOW);
    digitalWrite(ledb, LOW);
    delay(200);
  }
  //print(joyx);
  //print(joyy),
  Serial.print(anglex);
  Serial.print("   ");
  Serial.print(angley);
  Serial.println();
  delay(1000);
 
  
}
