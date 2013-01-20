#include <Castilla.h>

#define RED_LED 0
#define GREEN_LED 1
#define YELLOW_LED_1 2
#define YELLOW_LED_2 3

VUMeter lights;
TiltSwitch player_1 = TiltSwitch(10);
TiltSwitch player_2 = TiltSwitch(9);
void setup(){
  Serial.begin(9600);
  int pins[]={12,11,13,7};
  lights.config(4,pins);
  lights.initialize();
  player_1.initialize();
  player_2.initialize();
  //lights.fill(4);
  randomSeed(analogRead(0));
}
void loop(){
 lights.clear();
 lights.on(RED_LED);
 //Serial.println(random(5000,10000));
 delay(random(3000,6000));
 lights.off(RED_LED);
 lights.on(GREEN_LED);
 int winner=getWinner();
 if(winner==1)
   lights.on(YELLOW_LED_1);
 else
   lights.on(YELLOW_LED_2);
 delay(5000);
 
 //delay(1000);
  
}

int getWinner(){
  do{
    if(player_1.pressed(1))
      return 1;
    else if(player_2.pressed(1))
      return 2;
  }while(true);
}
