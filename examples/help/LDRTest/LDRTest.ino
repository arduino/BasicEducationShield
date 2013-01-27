/*	LDR test
*	This sketch should be used prior to using the component in 
*	Projects. Projects suitable for this library should have 2
*	states: uncovered and covered. That is to say, you want to 
*	track objects covering/moving pass the sensor.
*
*	HOW-TO:
*	Upload this sketch to Arduino, open the serial monitor. You
*	will see the current value of the ldr sensor. 
*
*	Make sure the sensor is in its desired setting and not 
*	moving. When the value gets stable, take note of it(we call 
*	it "baseValue"). 
*
*	Now cover the sensor with desired object. When the value 
*	gets stable, take note of it(topValue). Pick a value between 
*	this and the "baseValue", remember it as the "threshold".
*
*	"baseValue" and "threshold" will be used for defining the 
*	LDR switch in your project. You can fine tune the threshold
*	to make the sensor more/less sensitive. The closer to 
*	baseValue, the more sensitive it is. 
*
*/
#include <Castilla.h>

//Tinkerkit LDR is connected to analog 1.
LDR sensor = LDR(A1);

void setup(){
  Serial.begin(9600);
}

void loop(){
  //test() prints data to Serial port.
  sensor.test();
  delay(100);
}
