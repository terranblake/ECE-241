#include<LiquidCrystal.h>
LiquidCrystal LcdDriver(11, 9, 5, 6, 7, 8);

int minutes = 27;        //These global integers keep the value of the clock
int sec = 10;
int hr = 10;

const long interval = 1000;                                //This interval is equal to 1 second and will be added to seconds 
unsigned long oldMillis = 0;
int count;

void setup() {
  // put your setup code here, to run once:
  LcdDriver.begin(16, 2);
  LcdDriver.clear();
  LcdDriver.setCursor(0, 0);
}

void loop() {
  
//LcdDriver.setCursor(0,1); 
unsigned long currentMillis = millis();
  
  //This sets up the timer so that it can add one second to the integer
  if(currentMillis - oldMillis >= interval) {               
    oldMillis = currentMillis;
    
    sec++;
    
    LcdDriver.clear();

    LcdDriver.setCursor(0, 0);
    LcdDriver.print("  Current Time"); 
    
    LcdDriver.setCursor(4, 1);
    
    if(hr < 10) {
      //Prints an extra 0 if hr < 10
      LcdDriver.print(0);
      LcdDriver.print(hr);                                         
      LcdDriver.print(":");
      
    } else {
      //Print no zero if hours > 10
      LcdDriver.print(hr);
      LcdDriver.print(":");
      
    }
        
    if(minutes < 10) {
      //Prints an extra 0 if minutes < 10
      LcdDriver.print(0); 
      LcdDriver.print(minutes);
      LcdDriver.print(":");
      
    } else {
      //Print no zero if minutes > 10
      LcdDriver.print(minutes);
      LcdDriver.print(":");
      
    }
      
    if(sec < 10) {
      //Prints an extra 0 if seconds < 10
      LcdDriver.print(0);
      LcdDriver.print(sec); 
      
    } else {
      //Print no zero if seconds > 10
      LcdDriver.print(sec);
      
    }
  
    //Adds to minutes whenever seconds is == to 59
    if(sec == 59) {                                            
      minutes++; 
      sec = -1;
      
    }
    
    //Adds to hours whenever minutes is == to 59
    if(minutes == 60) {                                        
      hr++;
      minutes = 0; 

    }
    //Resets the clock whenever hours is == to 23
    if(hr == 24) {
      hr = 0;
      
    }  
  }
    
}
