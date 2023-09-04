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
int buzz = 11;
int colour = 13;

#include <Adafruit_SSD1306.h>
#define sensor A0
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(buzz, OUTPUT);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  // put your main code here, to run repeatedly:
   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
  
    char key = keypad.getKey(); //print the pressed key
    display.println("Key");
    display.println(key);
    display.println("was pressed");
    display.display();
    delay(100);
    
    //for key *
    if (key == '*'){
      Serial.println("Key *");
      digitalWrite(buzz, HIGH);
      delay(200);
      digitalWrite(buzz, LOW);
    }
    //for key 7
    if (key == '7'){
      Serial.println("Key 7");
      digitalWrite(colour, HIGH);
      delay(250);
      digitalWrite(colour, LOW);
    }
}
