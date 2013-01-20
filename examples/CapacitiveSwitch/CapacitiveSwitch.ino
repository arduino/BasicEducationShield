#include <CapacitiveSensor.h>

#include <Castilla.h>

CapacitiveSwitch me=CapacitiveSwitch();

void setup(){
  Serial.begin(9600);
  me.config(900);
}
void loop(){
  Serial.println("Please press...");
  Serial.println(me.pressed());
  //me.test();
}
