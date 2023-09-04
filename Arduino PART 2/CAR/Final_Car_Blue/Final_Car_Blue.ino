int LM1 = 8;
int LM2 = 7;
int RM1 = 11;
int RM2 = 10;

int speed1 = 3;
int speed2 = 6;

void setup() {
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  analogWrite(speed1, 255);
  analogWrite(speed2, 255);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    char data = Serial.read();
    switch(data)
    {
      case 'W': forward(); break;//forward
      case 'A': left(); break;//left
      case 'S': back(); break;//back
      case 'D': right(); break;//right
      case 'Q': Stop();; break;//Stop     
      default: break;
    }
    Serial.println(data);
  }
  delay(1000);

}

  void right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void left(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  void Stop(){ 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 

  }

  void back(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void forward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
