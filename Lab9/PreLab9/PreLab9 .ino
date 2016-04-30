void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  
}

unsigned long oldMillis = 0;

void loop() {
  unsigned long currentMillis = millis();
  int interval = 500;
  int SampleFromADC;

  if (millis() - oldMillis >= interval) { 
    SampleFromADC = analogRead(0);
    analogWrite (10, SampleFromADC/4);
    Serial.print(SampleFromADC);
    Serial.print( " = " );
    Serial.print( 3.3 * SampleFromADC / 1024.0, 4 );
    Serial.println( " volts " );
    oldMillis += interval;
  
  }
}
