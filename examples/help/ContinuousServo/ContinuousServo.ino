#include <Castilla.h>
#include <Servo.h>

// Servo is connected to tinkerkit digital 9
ContinuousServo me=ContinuousServo(9);

void setup(){
  me.begin(); //servo is initialized
}

void loop(){
/*
  Makes the servo spin in one direction. 
  The velocity can be changed by adding a number, me.goFoward(150).
  Numbers to be used are ca 100 to 180 
  The default value fo going forward is 180, this is the fastest
*/
  me.goForward(); 
  delay(2000); //wait two seconds
  
/*
  Makes the servo spin in the other direction. 
  The velocity can be changed by adding a number, me.goBackwards(30).
  Numbers to be used are 0 to ca 80
  The default value fo going backwards is 0, this is the fastest
*/
  me.goBackwards(); 
  delay(2000); //wait two seconds
  
/*
  Makes the servo stand still
  The value should be around 90 and differs from motor to motor
  The default value is 92 but you need to change it to fit your servo
  Try me.standStill(95), me.standStill(97) etc until you find the right one.
*/  
  me.standStill(); 
  delay(2000); //wait two seconds


/*
  Set what ever speed you want. 
  The values to be used are 0 to 180
*/    
  me.setSpeed(76); 
  delay(2000); //wait two seconds
}
