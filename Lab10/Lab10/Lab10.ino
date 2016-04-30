#include <TimerOne.h>;

int ledPin = 13; //pin for the led
unsigned long Timer2 = 0;
const long Timer2Interval = 10; //values for the timer
unsigned long currentMillis = millis();
const long DutyCycle = 551; //value for the PWM, has been edited for parts of lab

void setup() {

  pinMode (13,OUTPUT); //pin modes for the reading

  Timer1.initialize(100);
  Timer1.pwm(9, 0, 100);

  // Serial.begin(9600); //was used as a test to check timer
  // Serial.available();

}

void loop() {

  if( millis() - Timer2 > Timer2Interval) { //keeps the program in a 10ms interval

    Timer2 = Timer2 + Timer2Interval;

    bitSet(PORTB,5); //saves the frequency

    Timer1.setPwmDuty(9, analogRead(A0)); //reads the frequency

    bitClear(PORTB,5);

    // Serial.print("hello"); // test for the timer

  }
}
