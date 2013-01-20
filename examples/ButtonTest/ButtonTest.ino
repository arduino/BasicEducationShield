#include <Castilla.h>

Button me=Button(7,HIGH);

void setup(){
  Serial.begin(9600);
  delay(1000);
  me.initialize();
}
void loop(){
  Serial.println("Please press...");
  Serial.println(me.doublePressed());
  //Serial.println(digitalRead(7));

}
