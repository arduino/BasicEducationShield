#include "Castilla.h"

Joystick::Joystick(int x, int y){
	this->x=x;
	this->y=y;
}

int Joystick::getX(){
    int v = analogRead(x);
    if(v<300) return(-1);
    else if(v>700) return(1);
    else return(0);

}
int Joystick::getY(){
    int v = analogRead(y);
    if(v<300) return(-1);
    else if(v>700) return(1);
    else return(0);
}
