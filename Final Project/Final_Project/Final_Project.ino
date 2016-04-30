#include <Password.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

Password keypadPassword = Password( "0241" );
LiquidCrystal LcdDriver(11, 9, 5, 6, 7, 8);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'S','0','E','d'}
};

byte rowPins[ROWS] = { 19, 18, 17, 16 };
byte colPins[COLS] = { 15, 14, 12, 10 };

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
    
  Serial.begin(9600);

  LcdDriver.begin(16, 2);
  LcdDriver.clear();
  LcdDriver.setCursor(0, 0);
  LcdDriver.print("F1 to continue..");

  delay(10000);
  LcdDriver.clear();
  
  keypad.addEventListener(keypadEvent);

}

void loop() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A6, HIGH);
  digitalWrite(A7, HIGH);

  keypad.getKey();   //Saves input to memory

}

void loginMenu() {
  LcdDriver.print("Id#: ");
  keypad.getKey();
  
}
  
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
      switch (eKey) {
        case 'a':
          
          break;
        
        default:
          keypadPassword.append(eKey);
    
      }
  }
}

void checkKeypadPassword() {
  
  if (keypadPassword.evaluate()) {
    LcdDriver.clear();
    LcdDriver.print("Access Granted");
    
    delay(4000);
    LcdDriver.clear();
    
  } else {    
    LcdDriver.clear();
    LcdDriver.print("Access Denied");

      delay(4000);
    LcdDriver.clear();

  }
}
