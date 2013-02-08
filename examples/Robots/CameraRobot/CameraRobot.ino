/*
*  Camera Robot
* This camera robot will help you spy. Mount a web camera on the pan tilt 
* construction and you will be able to control the direction of it using 
* a small joystick. You can monitor everything from the computer and when 
* you see something suspicious, take a picture of it!
*
*/

#include <Castilla.h>
#include <Servo.h>

//The joystick uses two analog pins. Here pin A0 and A1 is used

Joystick joystick = Joystick(A1,A0);//Joystick(XanalogPin, YanalogPin)

Servo pan, tilt;

int panAngle = 90; //Pan angle
int tiltAngle = 90; //Tilt angle

int panJoystick = 0;
int tiltJoystick = 0;

void setup(){
  //servos are initialized
  pan.attach(9); 
  tilt.attach(10); 
}
void loop(){
  panJoystick = joystick.getX(); //Get X value from joystick
  tiltJoystick = joystick.getY(); //Get Y value from joystick
  
  //If the joysticks x value isn't 0 we will pan 
  if(panJoystick!=0){
    tilt.detach(); 
    pan.attach(9);
    //If the X value from the joystick equals 1 and
    //panAngle is less than 180 degrees, increase panAngle with 1
    if(panJoystick==1 && panAngle<180) panAngle++;
    //If the X value from the joystick equals -1 and
    //panAngle is more than 0 degrees, decrease panAngle with 1
    else if(panJoystick==-1 && panAngle>0) panAngle--;
    pan.write(panAngle); //Set position of the pan servo
  }
  //If the joysticks x value is 0 we will tilt
  else{ 
    pan.detach();
    tilt.attach(10);
    //If the Y value from the joystick equals 1 and
    //tiltAngle is less than 180 degrees, increase tiltAngle with 1
    if(tiltJoystick==1 && tiltAngle<180) tiltAngle++; 
    //If the Y value from the joystick equals -1 and
    //tiltAngle is more than 0 degrees, decrease tiltAngle with 1
    else if(tiltJoystick==-1 && tiltAngle>0) tiltAngle--;
    tilt.write(tiltAngle); //Set position of the tilt servo 
  }
  delay(5);
}
