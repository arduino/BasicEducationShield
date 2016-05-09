/*
  OpenBox
  
  OpenBox is an open source box that contains open source 
  electronics. Oh, and it automatically opens when you 
  knock on it. 
  
  (c) 2013 Arduino LLC
*/

#include <BasicEducationShield.h>

//It's necessary to include Servo.h if servo is used
#include <Servo.h>

//Declare the pezio knock sensor. Connected to A0
PiezoKnockSensor sensor=PiezoKnockSensor(A0);

//Declare the servo motor for opening the lid
Servo lidOpener;

void setup(){
  //define the threshold and debounce time of the knock
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from detecting
  //false knocks, but also limits how rapid you can knock.
  //See the PiezoKnockSensor sketch in the help folder
  //to make sure your values are correct
  sensor.config(40,80);

  //initialize the servo
  lidOpener.attach(9);
  //Rotate servo to close lid
  lidOpener.write(60);
}
void loop(){

  if(sensor.knocked()){
	//rotate the servo motor to open the lid
    lidOpener.write(0);
    delay(3000); //Wait for 3 seconds
    //close the lid
    lidOpener.write(60);
    delay(200);
  }

}
