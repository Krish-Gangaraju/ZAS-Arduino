#include <IRremote.h>

int IR = 11;
int green = 2;
int red = 3;
IRrecv irrecv(IR);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Enter any a channel number from 420 to 430");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
     Serial.println(results.value, DEC);
    irrecv.resume();
  }
  if (results.value == 12582916)//4
  {
    if (results.value == 12582914)//2
    {
      if (results.value == 12582912)//0
      {
        Serial.println("Comedy Central");
      }
      else if (results.value == 12582913)//1
      {
        Serial.println("Cartoon Network");
      }
      else if (results.value == 12582914)//2
      {
        Serial.println("Disney XD");
      } 
      else if (results.value == 12582915)//3
      {
        Serial.println("Star Sports");
      } 
      else if (results.value == 12582916)//4
      {
        Serial.println("HBO Movies");
      }  
      else if (results.value == 12582917)//5
      {
        Serial.println("Star Plus");
      }  
      else if (results.value == 12582918)//6
      {
        Serial.println("National Geographic");
      } 
      else if (results.value == 12582919)//7
      {
        Serial.println("History TV18");
      } 
      else if (results.value == 12582920)//8
      {
        Serial.println("Marvel TV");
      } 
      else if (results.value == 12582921)//9
      {
        Serial.println("Learning Coding");
      }
    }
    else if (results.value == 12582915)//3
    {
      if (results.value == 12582912)//0
      {
        Serial.println("Showcase");
      } 
      else{
        digitalWrite(red, HIGH);
      }
    }
      else{
      digitalWrite(red, HIGH);
     }
   }
    
 
}
