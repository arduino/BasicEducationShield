/*	
  VU-Meter
*/

#include <BasicEducationShield.h>

//Declare the VUMeter
VUMeter me;
int pins[]={2,3,4,5,6};
int pinCount=5;

void setup(){
  //Configure the VU meter using parameters defined previously.
  me.config(pinCount,pins);

  //initialize the component. Must be called.
  me.begin();

}
void loop(){
  //Fill 5 LEDs
  me.fill(5);
  delay(3000);

  //turn all the LEDs off
  me.clear();
  delay(1000);

  //Turn the 3rd LED on
  me.on(2);
  delay(1000);

  //Turn the 3rd LED off
  me.off(2);
  delay(1000);

  //One LED light up at a time, scroll from left to right
  me.scrollRight(700);

  //And then scroll back from the 2nd on the right
  me.scrollLeft(700,1);

  //the 3rd led will be blinking for 10 times, each time
  //with 100 milliseconds on and 100 milliseconds off
  me.blink(2,100,10);

  //All LEDs will be blinking 10 times
  me.blinkAll(100,10);

  //The 2nd to 4th LED will be light up
  me.fillFrom(1,3);
  delay(2000);
}
