#include <Castilla.h>

VUMeter me;

void setup(){
  Serial.begin(9600);
  int pins[]={2,3,4,5,6};
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
  me.fill(5);
}
