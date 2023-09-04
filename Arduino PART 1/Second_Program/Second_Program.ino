
int c;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
 
  int b = 2;
  //int c = a+b;

}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 75;
  int b = 67;
   c = a + b;
  Serial.println(c);

}
