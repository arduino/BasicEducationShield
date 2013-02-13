/*  Test for example "Vechile"
*
*  Use this sketch if example Vechile does not work
*  properly. It allows you to get the reading of 
*  left and right LDR, so you can change the baseValue
*  and threshold of Vechile example accordingly.
*
*/
#include <Castilla.h>

//Declare the left and right LDR sensor
LDR sensorLeft=LDR(A0);
LDR sensorRight=LDR(A2);

void setup(){
  Serial.begin(9600);
}
void loop(){
  //Print out the left LDR reading
  sensorLeft.test();
  
  Serial.print("\t");
  
  //Print out the right LDR reading
  sensorRight.test();
}
