int LM1 = 8;
int LM2 = 7;

int RM1 = 11;
int RM2 = 10;

int EchoPin = 4;
int TrigPin = 2;

int speed1 = 3;
int speed2 = 6;

int Distance;
int EchoTime;

void setup() {
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  analogWrite(speed1, 200);
  analogWrite(speed2, 200);

  Serial.begin(9600);
  

}

void loop() {
  findDistance();
  if(abs(Distance) > 40){
    forward();
  }

  else{
    left();
    delay(100);
    
  }

  

}
  void findDistance(){
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    EchoTime = pulseIn(EchoPin, HIGH);
    Distance = (EchoTime/2)*(0.034);
    Serial.print("Distance: ");
    Serial.println(Distance);
  }

  void forward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  void backward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  void Stop(){ 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 

  }

  void left(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  void right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
