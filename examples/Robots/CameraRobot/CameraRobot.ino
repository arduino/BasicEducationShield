
#include <Castilla.h>
#include <Servo.h>

//The joystick uses two analog pins. Here pin A0 and A1 is used

Joystick joystick = Joystick(A1,A0);//Joystick(XanalogPin, YanalogPin)

LimitedServo pan = LimitedServo(9); //Servo on the bottom that pans
LimitedServo tilt = LimitedServo(10); //Servo that tilts

int xAngle = 90; //Pan angle
int yAngle = 90; //Tilt angle

void setup(){
  Serial.begin(9600);
  pan.begin(); //servo is initialized
  tilt.begin(); //servo is initialized
}
void loop(){
  if(joystick.getX()==1 && xAngle<180){
    //If the X value from the joystick equals 1 and
    //xAngle is less than 180 degrees, increase xAngle with 1
    xAngle++;
  }
  else if(joystick.getX()==2 && xAngle>0
    //If the X value from the joystick equals 2 and
    //xAngle is more than 0 degrees, decrease xAngle with 1
    xAngle--;
  }
  
  if(joystick.getY()==1 && yAngle<180){ 
    //If the Y value from the joystick equals 1 and
    //yAngle is less than 180 degrees, increase yAngle with 1
    yAngle++; 
  }
  else if(joystick.getY()==2 && yAngle>0){ 
    //If the Y value from the joystick equals 2 and
    //yAngle is more than 0 degrees, decrease xAngle with 1
    yAngle--;
  }
  
  pan.setAngle(xAngle); //Set position of the pan servo
  tilt.setAngle(yAngle); //Set position of the tilt servo
  delay(5);
}
