/* 
* This is an open source box. More importantly, 
* it’s a automatic opening box. When you knock on it, 
* the box opens. Save/take your candies from it, 
* and the box closes by itself.
*/

#include <Castilla.h>

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
  sensor.config(200,80);
  
  //initialize the servo
  lidOpener.attach(9);
  //Rotate servo to close lid
  lidOpener.write(0); 
}
void loop(){

  if(sensor.knocked()){
	//rotate the servo motor to open the lid
    lidOpener.write(60);
    delay(3000);
	//close the lid
    lidOpener.write(0);
    delay(200);
  }
  
}
