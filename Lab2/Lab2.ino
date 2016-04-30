

// Non-Constant Variables :
int LedTimer = LOW;             // Intiger used to set up LED 
int shortTimer = LOW;
unsigned long oldMillis = 0; // will store last time LED was updated
unsigned long olderMillis = 0; // will store last time LED was updated

// Constant Variables :
const long interval = 20;           // How often LED will blink
const long shortinterval = 10;


void setup()
{
  // Makes pin 13 as an OUTPUT
  pinMode(13, OUTPUT);
  // Makes pin 12 as an OUTPUT
  pinMode(12, OUTPUT);
}

void loop()
{

  // Will use the timer to find whether it is time to blink or not
  unsigned long currentMillis = millis();

  if(currentMillis - oldMillis >= shortinterval)
  {
    // save the last time you blinked the LED
    oldMillis = currentMillis;

//    // if the LED is off turn it on and vice-versa
//    if (LedTimer == LOW)
//      LedTimer = HIGH;
//    PORTB |= 0x10; // Force bit 2, pin 12, high
//    else
//      LedTimer = LOW;

    // set the LED with the ledState of the variable:
    //digitalWrite(13, LedTimer);
    PORTB |= 0x10; // Force bit 2, pin 12, high
    PORTB &= ~0x10; // Force bit 2, Pin 12, low

//  //Same idea as the last counter but on a much faster pace and must be tested with Logic Probe
//  if(currentMillis - olderMillis >= interval)
//  {
//    olderMillis = currentMillis;
//
//    if (shortTimer == LOW)
//    {
//      shortTimer = HIGH;
//      PORTB |= 0x10; // Force bit 2, pin 12, high
//    }
//    else
//    {
//     shortTimer = LOW;
//    }
//     //Asigns timer to pin
//     //digitalWrite(12, shortTimer);
//     PORTB &= ~0x10; // Force bit 2, Pin 12, low
//    }
  } //end of loop
} //end of program

