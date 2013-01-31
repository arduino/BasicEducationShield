#include <Castilla.h>
#include <Servo.h>

// Servo is connected to tinkerkit digital 9
Robot me=Robot(9);

void setup(){
  me.begin(); //servo is initialized
}

void loop(){
  me.goForward(); //Makes the servo spin in one direction
  delay(2000); //wait two seconds
  me.goBackwards(); //Makes the servo spin in the other direction
  delay(2000); //wait two seconds
  me.standStill(); //Makes the servo stand still
  delay(2000); //wait two seconds
}
