#include<LiquidCrystal.h>                                                                 //These two lines setup the drivers for the display
LiquidCrystal LcdDriver(12, 11, 5, 6, 7, 8);  

int x = 0; 

void setup() {                                                                 //Begins Lcd on pin 16 and 2 
  LcdDriver.begin(16, 2);
  LcdDriver.clear();
  LcdDriver.setCursor(0,0);

}

void loop(){
  
  LcdDriver.print(x);
  delay(500);
  LcdDriver.clear();
  x++;
  
}
