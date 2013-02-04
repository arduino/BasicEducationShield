/*	StandardServo
*	
*	Standard servo is a type of motor which has 
*	limited rotation angle. And you have precise 
*	control over which angle it should be pointing
*	to.
*
*	A micro servo is same as standard servo, just
*	slimmer and has less strength.
*
*/
#include <Castilla.h>

//It's necessary to include Servo.h if servo is used
#include <Servo.h>

// Servo is connected to TinkerKit digital 9
StandardServo me=StandardServo(9);

void setup(){
  //servo is initialized
  me.begin(); 
}

void loop(){
  //setAngle(angle):
  //	angle: the angle to which you want to rotate
  //	the servo. It is ranged between 0 and 180. 
  //
  //Make the servo rotate to 76 degrees.
  me.setAngle(76);
}
