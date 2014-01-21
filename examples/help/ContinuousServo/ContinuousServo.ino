/*	ContinuousServo
*/

#include <BasicEducationShield.h>
#include <Servo.h>
Servo me;

void setup(){
  me.attach(9);
}

void loop(){
  //Make the servo rotate in speed 120.
  me.write(120);

}
