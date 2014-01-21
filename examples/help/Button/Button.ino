/*	
  Button
*/

#include <BasicEducationShield.h>

//Declare the button component.
Button me=Button(9,HIGH);

void setup(){
  Serial.begin(9600);
  me.begin();
}
void loop(){
  Serial.println("Please press...");
  //Wait until the button is pressed.
  Serial.println(me.pressed());


  Serial.println("Please release...");
  //Wait untill the button is released.
  Serial.println(me.released());


  Serial.println("Please double press...");

  //Wait untill the button is double clicked. If only clicked
  //once or action is too slow, it will return 0.
  Serial.println(me.doublePressed());

}
