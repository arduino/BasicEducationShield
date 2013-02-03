
#include <Castilla.h>

//The joystick uses two analog pins. Here pin A0 and A1 is used
Joystick me=Joystick(A1,A0);

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.print("X: ");  
  Serial.print(me.getX()); //Print the X value. 0 is middle
  Serial.print("  Y: ");
  Serial.println(me.getY()); //Print the Y value. 0 is middle
  delay(200);
}
