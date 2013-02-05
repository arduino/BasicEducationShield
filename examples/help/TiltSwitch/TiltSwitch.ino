/*  TiltSwitch
*
*  Convenient for detecting if a tilt switch is tilted.
*
*/
#include <Castilla.h>

//Declare the tilt switch. A TinkerKit tilt switch can be 
//connected to TinkerKit port digital 10 or 9(We use 10 here). 
TiltSwitch me=TiltSwitch(10);

void setup(){
  Serial.begin(9600);
  
  //Initialize the component. Must be called.
  me.begin();
}
void loop(){
  Serial.println("Please tilt...");
  
  //pressed(timeout)
  //	timeout: milliseconds within which the tilt switch should 
  //		be tilted. If tilted within time, the function
  //		returns 1, otherwise 0. If not used, it waits 
  //		untill being pressed. 
  //
  //Wait until the tilt switch is tilted.
  Serial.println(me.pressed());

}
