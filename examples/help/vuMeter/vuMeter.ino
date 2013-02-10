/*	VU-Meter
*
*	VU-Meter is a few LEDs grouped together into a line.
*
*	LEDs are connected to Arduino in such way: The long 
*	leg is connected to a 220 ohm resistor to a digital
*	pin, the short leg is connected to GND. 
*
*	When a few LEDs are used as VU-Meter, the short legs
*	are typically connected together, then to a GND pin
*	on Arduino.
*
*	This library has some of the most often used feature 
*	for controlling LEDs, can be used as a score board, 
*	conveniently managing the LEDs in a project, or even 
*	being used as the major part of a game.
*
*/

#include <Castilla.h>

//Declare the VUMeter
VUMeter me;

//The pins used by the VUMeter, default to 2-6. Can be
//customized as wish, but do change the pinCount if the 
//number of LEDs are changed.
int pins[]={2,3,4,5,6};

//How many pins are used. Should refect the pins array above.
int pinCount=5;

void setup(){
  //Configure the VU meter using parameters defined previously.
  me.config(pinCount,pins);
  
  //initialize the component. Must be called.
  me.begin();
  
}
void loop(){
  //fill(number)
  //  number: how many leds from left shall be light up
  //
  //Fill 5 LEDs
  me.fill(5);
  delay(3000);
  
  //clear()
  //
  //turn all the LEDs off
  me.clear();
  delay(1000);
  
  //on(index)
  //  index: which LED being turned on
  //
  //Turn the 3rd LED on
  me.on(2);
  delay(1000);
  
  //off(index)
  //  index: which LED being turned off
  //
  //Turn the 3rd LED off
  me.off(2);
  delay(1000);
  
  //scrollRight(speed, startIndex)
  //  speed: milliseconds before the next LED turns on
  //  startIndex: from which LED to the left it start 
  //     scrolling. If not specified, it's 1.
  //
  //One LED light up at a time, scroll from left to right
  me.scrollRight(700);
  
  //scrollLeft(speed, startIndex)
  //  speed: milliseconds before the next LED turns on
  //  startIndex: from which LED TO THE RIGHT it start 
  //     scrolling. If not specified, it's 1.
  //
  //And then scroll back from the 2nd on the right
  me.scrollLeft(700,1);

  //blink(index, speed, times)
  //  index: which LED should blink
  //  speed: milliseconds, of which the LED light on and off
  //  times: how many times the LED blinks. Defaults to 1
  //
  //the 3rd led will be blinking for 10 times, each time 
  //with 100 milliseconds on and 100 milliseconds off
  me.blink(2,100,10);
  
  //blinkAll(speed, times)
  //  speed: milliseconds, of which all LEDs light on and off
  //  times: how many times the LED blinks. Defaults to 1
  //
  //All LEDs will be blinking 10 times
  me.blinkAll(100,10);
  
  //fillFrom(leftIndex,rightIndex)
  //  leftIndex: start filling from which LED
  //  rightIndex: end filling to which LED
  //
  //The 2nd to 4th LED will be light up
  me.fillFrom(1,3);
  delay(2000);
  
}
