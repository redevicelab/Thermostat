#include "Thermostat.h"

Thermostat regulator(HEAT,LOW);

void setup() {
  pinMode(13, OUTPUT);        
  regulator.setPointValue(35);    
  regulator.setHysteresis(5);   
}

void loop() {
  int temp;                 
  regulator.setInputValue(temp);   
  digitalWrite(13, regulator.getResult()); 
  delay(100);
}
