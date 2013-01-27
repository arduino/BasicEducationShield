#include <CapacitiveSensor.h>

#include <Castilla.h>

/*
 * Elektor Monster Jar February 2013
 *
 * File Elektor_feb13_monsterjar.ino
 *
 * Read the value of the a capacitive sensor between pins 4 and 5 and 
 * turn on a ultra-bright LED to light up the scene as well as send
 * a character "p" (as in "picture") over serial when detecting the 
 * value on the touch sensor went over a threshold.
 *
 * We place a 1M resistor between pins 4 and 5 and use pin 5 as touchpad.
 * Pin 7 is connected to the ultra-bright white LED.
 *
 * You will have to configure the value of the THRESHOLD constant for the
 * program to operate properly. Follow these steps:
 *
 * 1) connect your circuit to the aluminium folie
 * 2) measure the default value, depending on how much folie you have this 
 *    value could be in the range of 200
 * 3) touch the sensitive area and observe the measurement in the Serial Monitor
 * 4) make THRESHOLD = (MAX_VALUE + DEFAULT_VALUE) / 2 and change it in the code
 *
 * (c) 2013 B&D Cuartielles
 *
 * This code is Free Software, licensed under GPLv3
 * Based on code by Paul Badger 2008
 *
 */

//Define the capacitive sensor
CapacitiveSwitch sensor=CapacitiveSwitch(13,12);
//Use Tinkerkit LED(or Tinkerkit LED matrix) here. 
//Deinfe the LED
LED led=LED(9);

void setup()                    
{
   // configure the serial port
   Serial.begin(9600);
   
   //initialize components
   sensor.config(200);
   led.begin();
}

void loop(){
  //When someone attempts to open the
  //cookie jar, the sensor is activated
  if(sensor.pressed()){
    //Sends signal to processing, so a picture
    //will be captured
    Serial.write('p');
    //Turn on the LED for 2 seconds afterwards
    led.on();
    delay(2000);
    led.off();
  }
}

