#include <Castilla.h>

//Position of the leds in VU-meter is represented
//By their names here. So we can use names to
//find LEDs later
#define RED_LED 0
#define GREEN_LED 1
#define YELLOW_LED_1 2
#define YELLOW_LED_2 3

//An array stores which pins the VU-meter is connected
int ledPins[]={2,3,4,5};
//How many pins are used by VU-meter
int pinCount=4;
VUMeter lights;

TiltSwitch player_1 = TiltSwitch(10);
TiltSwitch player_2 = TiltSwitch(9);

void setup(){
  lights.config(pinCount,ledPins);

  //Initializing components
  lights.initialize();
  player_1.initialize();
  player_2.initialize();

  //We need this for generating random number later
  randomSeed(analogRead(0));
}
void loop(){
 lights.clear();

 //Red led means both of you should hold the tilter 
 //switch sword up
 lights.on(RED_LED);

 //Wait for a random period of time, between 3 seconds
 //And 6 seconds. Get ready!
 delay(random(3000,6000));

 lights.off(RED_LED);
 //When the green led turns on, game starts
 lights.on(GREEN_LED);
 
 //Swing your swords as fast as you can, the faster one
 //Will be returned by getWinner()
 int winner=getWinner();

 //The yellow led by side of the winner will light up
 if(winner==1)
   lights.on(YELLOW_LED_1);
 else
   lights.on(YELLOW_LED_2);
 delay(5000);
 
}

//The function below waits for either of the tilter 
//switch to be activated. The first one to activate
//will be returned by its number
int getWinner(){
  do{
    if(player_1.pressed(1))
      return 1;
    else if(player_2.pressed(1))
      return 2;
  }while(true);
}
