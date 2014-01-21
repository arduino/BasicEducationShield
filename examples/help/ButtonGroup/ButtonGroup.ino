/*  
  ButtonGroup
*/
#include <BasicEducationShield.h>

//Declaring the button group
ButtonGroup bg;

//Delcaring the pins to which the buttons are connected
int buttons[]={4,5,6};

void setup(){
  Serial.begin(9600);
  bg.begin(3,buttons);
}
void loop(){
  Serial.println("Please press a button");
  //Wait until one button is pressed.
  Serial.println(bg.pressed());
  delay(10);
}
