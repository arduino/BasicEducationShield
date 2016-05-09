/*	
  Button
  A button is a digital input. This means that it can have two 
  states, either HIGH (5V) or LOW (0V). When you connect a button 
  to your Arduino board you can read these states as 1 or 0. 
  
  (c) 2013 Arduino LLC
*/

#include <BasicEducationShield.h>

//Declare the button component.
//9 is the pin number. If it's a tinkerkit button, use 9 or 10.
//HIGH can be ignored mostly, which means when the button is
//pressed, what state it is in.
Button me=Button(9,HIGH);

void setup(){
  Serial.begin(9600);

  //Initialize the component. Must be called.
  me.begin();
}
void loop(){
  Serial.println("Please press...");
  //pressed(timeout)
  //	timeout: milliseconds within which the button should
  //		be pressed. If pressed within time, the function
  //		returns 1, otherwise 0. If not used, it waits
  //		untill being pressed.
  //
  //Wait until the button is pressed.
  Serial.println(me.pressed());


  Serial.println("Please release...");
  //released(timeout)
  //	timeout: same as in pressed(timeout).
  //
  //Wait untill the button is released.
  Serial.println(me.released());


  Serial.println("Please double press...");
  //doublepressed(timeout, tolerance)
  //	timeout: milliseconds before the button should be
  //		pressed for the first time. Same as others.
  //	tolerance: milliseconds before it should be clicked
  //		the second time. Defaults to 500.
  //
  //Wait untill the button is double clicked. If only clicked
  //once or action is too slow, it will return 0.
  Serial.println(me.doublePressed());

}
