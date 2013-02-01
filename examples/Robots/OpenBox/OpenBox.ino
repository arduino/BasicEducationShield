#include <Castilla.h>

//It's necessary to include Servo.h if servo is used
#include <Servo.h> 

//Declare the pezio knock sensor. Connected to A5
PiezoKnockSensor sensor=PiezoKnockSensor(A5);

//Declare the servo motor for opening the lid
LimitedServo lidOpener=LimitedServo(9);

void setup(){
  //define the threshold and debounce time of the knock 
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from detecting 
  //false knocks, but also limits how rapid you can knock.
  sensor.config(40,80);
  
  //initialize the servo
  lidOpener.begin();
}
void loop(){
  //Knock the box to open it
  if(sensor.knocked()){
	//rotate the servo motor to open the lid
    lidOpener.setAngle(170);
    delay(3000);
	//close the lid
    lidOpener.setAngle(10);
    delay(500);
  }
}