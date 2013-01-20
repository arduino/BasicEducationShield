/*

*/
#include <Castilla.h>

LDR ldr = LDR(A1);

void setup(){
  Serial.begin(9600);
}

void loop(){
  ldr.test();
  delay(100);
}
