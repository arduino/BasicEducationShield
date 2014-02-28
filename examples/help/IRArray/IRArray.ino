/*
  IRArray
  This program will print each IR sensor reading to the 
  serial monitor.
  
  When you hold the IRarray over a white surface all sensors 
  should give you a value of 400. When held over a black surface 
  it should go down to around 330. Make sure that you've 
  connected all sensor pins right by alternate each sensor 
  between black and white and see the that values of the 
  corresponding IR sensor is changing. E.g. if you move IR1 from 
  black to white but only the value of IR2 is changed you need 
  to either change the analog pins in the code or change the 
  connections to the analog pins on the Arduino. 
  
  (c) 2014 Arduino Verkstad
*/

#include <BasicEducationShield.h>

//IRArray(IR1, IR2, IR3)
IRArray ir = IRArray(A1, A2, A3);

void setup(){
  Serial.begin(9600);
}

void loop(){
  ir.test();
}
