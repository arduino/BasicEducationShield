
#include <Castilla.h>
#include <Servo.h>

//The joystick uses two analog pins. Here pin A0 and A1 is used

Joystick joystick = Joystick(A1,A0);//Joystick(XanalogPin, YanalogPin)

LimitedServo pan = LimitedServo(9); //Servo on the bottom that pans
LimitedServo tilt = LimitedServo(10); //Servo that tilts

int panAngle = 90; //Pan angle
int tiltAngle = 90; //Tilt angle

void setup(){
  Serial.begin(9600);
  pan.begin(); //servo is initialized
  tilt.begin(); //servo is initialized
}
void loop(){
  if(joystick.getX()==1 && panAngle<180){
    //If the X value from the joystick equals 1 and
    //panAngle is less than 180 degrees, increase panAngle with 1
    panAngle++;
  }
  else if(joystick.getX()==2 && panAngle>0){
    //If the X value from the joystick equals 2 and
    //panAngle is more than 0 degrees, decrease panAngle with 1
    panAngle--;
  }
  
  if(joystick.getY()==1 && tiltAngle<180){ 
    //If the Y value from the joystick equals 1 and
    //tiltAngle is less than 180 degrees, increase tiltAngle with 1
    tiltAngle++; 
  }
  else if(joystick.getY()==2 && tiltAngle>0){ 
    //If the Y value from the joystick equals 2 and
    //tiltAngle is more than 0 degrees, decrease tiltAngle with 1
    tiltAngle--;
  }
  
  pan.setAngle(panAngle); //Set position of the pan servo
  tilt.setAngle(tiltAngle); //Set position of the tilt servo
  delay(5);
}
