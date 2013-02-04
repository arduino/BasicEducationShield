/*	ContinuousServo
*
*	Continuous servo looks the same as a standard servo, but it’s 
*	capable of rotating continuous like a normal motor. You can not 
*	control which angle it’s pointing to, but you can specify how 
*	fast it spins, and which direction it spins. 
*
*/
#include <Castilla.h>

//It's necessary to include Servo.h if servo is used
#include <Servo.h>

//ContinuousServo(pin, direction):
//	pin: the pin to which the servo is connected.
//	direction: specify which direction the servo is facing at.
//		can be true or false, and defaults to true. If you use
//		2 servos as wheels, as they have different facing directions,
//		"forward" actually means different things. So one of them 
//		need to have direction as false. 
//
// Servo is connected to tinkerkit digital 9
ContinuousServo me=ContinuousServo(9);

void setup(){
  //begin(stillSpeed):
  //	stillSpeed: A value for calibrating the servo. Default to 
  //	97, and normally you don't need to care the value at all.
  //	If the motor does not keep fully still when standStill() 
  //	is called, change this value slightly(for example, 96 or
  //	98) to make it still. May need some experimenting to get 
  //	the right value.
  //
  //call begin to initialize the servo.
  me.begin(); 
}

void loop(){
  //goForward(speed):
  //	speed: how fast the servo goes. Can be a value between 0 and
  //	100, and defaults to 100(full speed). 
  //
  //Make the servo go forward 
  me.goForward(); 
  delay(2000); //wait two seconds
  
  //goBackwards(speed):
  //	speed: how fast the servo goes. Can be a value between 0 and
  //	100, and defaults to 100(full speed). 
  //
  //Make the servo go backwards 
  me.goBackwards(); 
  delay(2000); //wait two seconds
  
  //standStill():
  //
  //Make the servo stay still.
  me.standStill(); 
  delay(2000); //wait two seconds


  //setSpeed(speed):
  //	speed:a value between 0 and 180. A middle point(most likely 97)
  //	make the servo still. Smaller than the middle point makes the 
  //	servo go one direction. Bigger than the middle point makes the 
  //	servo go the other direction.
  //
  //Using the raw power of continuous servos, advanced usage only! Control
  //both speed and direction of the servo with one value. setSpeed(76) is
  //similar to goBackwards(20) if direction is set to true.
  me.setSpeed(76); 
  delay(2000); //wait two seconds
}
