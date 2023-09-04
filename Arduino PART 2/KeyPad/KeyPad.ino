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
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    char key = keypad.getKey(); //print the pressed key
    if (key){
     // Serial.print(key);
    }

    //for key 1
    if (key == '1'){
      Serial.println("Key 1 was pressed");
    }
    //for key 2
    if (key == '2'){
      Serial.println("Key 2 was pressed");
    }
    //for key 3
    if (key == '3'){
      Serial.println("Key 3 was pressed");
    }
    //for key A
    if (key == 'A'){
      Serial.println("Key A was pressed");
    }
    //for key 4
    if (key == '4'){
      Serial.println("Key 4 was pressed");
    }
    //for key 5
    if (key == '5'){
      Serial.println("Key 5 was pressed");
    }
    //for key 6
    if (key == '6'){
      Serial.println("Key 6 was pressed");
    }
    //for key B
    if (key == 'B'){
      Serial.println("Key B was pressed");
    }
    //for key 7
    if (key == '7'){
      Serial.println("Key 7 was pressed");
    }
    //for key 8
    if (key == '8'){
      Serial.println("Key 8 was pressed");
    }
    //for key 9
    if (key == '9'){
      Serial.println("Key 9 was pressed");
    }
    //for key C
    if (key == 'C'){
      Serial.println("Key C was pressed");
    }
    //for key *
    if (key == '*'){
      Serial.println("Key * was pressed");
    }
    //for key 0
    if (key == '0'){
      Serial.println("Key 0 was pressed");
    }
    //for key #
    if (key == '#'){
      Serial.println("Key # was pressed");
    }
    //for key D
    if (key == 'D'){
      Serial.println("Key D was pressed");
    }
}
