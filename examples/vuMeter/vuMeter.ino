#include <Castilla.h>

VUMeter me;

void setup(){
  Serial.begin(9600);
  int pins[]={9,10,11,12,13};
  me.config(5,pins);
  me.begin();
//  me.test();
  //me.scrollLeft(500);
}
void loop(){
  //me.scrollRight(500,1);
  //me.scrollLeft(500,1);
  //me.fillFrom(2,3);
  //me.blink(2,100,10);
  //me.blinkAll(100,10);
  me.fill(3);
}
