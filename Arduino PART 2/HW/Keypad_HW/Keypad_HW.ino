#include<Keypad.h>

const byte rows = 4; //4 rows
const byte columns = 4; //4 columns
char keys[rows][columns] = {
   {'1', '2', '3', 'A'},
   {'4', '5', '6', 'B'},
   {'7', '8', '9', 'C'},
   {'*', '0', '#', 'D'}
  };

    byte rowPINS[rows] = {2, 3, 4, 5};
    byte colPINS[columns] = {6, 7, 8, 9};

    Keypad keypad = Keypad( makeKeymap(keys), rowPINS, colPINS, rows, columns );
int red = 11;
int colour = 12;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(colour, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    char key = keypad.getKey(); //print the pressed key

    //for key 1
    if (key == '1'){
      Serial.println("Star Sports 1");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key 2
    if (key == '2'){
      Serial.println("Star Sports 2");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    
    //for key 3
    if (key == '3'){
      Serial.println("History TV 18");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    
    //for key A
    if (key == 'A'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
    //for key 4
    if (key == '4'){
      Serial.println("National Geographic");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key 5
    if (key == '5'){
      Serial.println("Cartoon Network");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key 6
    if (key == '6'){
      Serial.println("Disney XD");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key B
    if (key == 'B'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
    //for key 7
    if (key == '7'){
      Serial.println("HBO Movies");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key 8
    if (key == '8'){
      Serial.println("Star Movies");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key 9
    if (key == '9'){
      Serial.println("Comedy Central");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key C
    if (key == 'C'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
    //for key *
    if (key == '*'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
    //for key 0
    if (key == '0'){
      Serial.println("Showcase");
      digitalWrite(colour, HIGH);
      delay(100);
      digitalWrite(colour, LOW);
    }
    //for key #
    if (key == '#'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
    //for key D
    if (key == 'D'){
      Serial.println("No Channel Found");
      digitalWrite(red, HIGH);
      delay(100);
      digitalWrite(red, LOW);
    }
}
