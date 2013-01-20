#include <Castilla.h>

LDR me=LDR(A1);

void setup(){
  Serial.begin(9600);
  me.config(730,600);
  delay(1000);
}

void loop(){
  //me.test();
  //delay(30);

  Serial.println("Please press ldr...");
  Serial.println(me.pressed());
}
