#ifndef IntelCTC_h
#define IntelCTC_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Servo.h>

/*
#include <CapacitiveSensor.h>
#include <utility/SdFat.h>
#include <utility/SdFatUtil.h>
#include <SD.h>
*/

#define LED_LENGTH 20
#define BUTTONGROUP_LENGTH 10

class VUMeter{
	public:
		VUMeter();
		void config(int length, int pins[]);
		void begin();
		void on(int index);
		void off(int index);
		void scrollLeft(int speed,int startIndex=0);
		void scrollRight(int speed,int startIndex=0);
		void fill(int length);
		void fillFrom(int leftIndex,int rightIndex);
		void blink(int index, int speed, int times=1);
		void blinkAll(int speed,int times=1);
		void clear();

		void test();
	private:
		void blinkOnce(int index,int onTime,int offTime);
		//int getPin(int index);
		int pins[LED_LENGTH];
		int pinCount;
};

#define MELODY_LENGTH 32

class Melody{
	public:
		Melody(int pin);
		void play(int length, int notes[],int diration[], float speed=1.3);
		void beep(int note=20, int length=30);
		void playTone(int note, int length=10);

		void effect_win();
		void effect_gameover();
		void effect_score();

	private:
		int pin;

};

class Button{
	public:
		Button(int pin=8,bool pressedValue=HIGH);
		void begin();
		bool pressed(int timeout=0);
		bool released(int timeout=0);
		bool doublePressed(int timeout=0,int tolerance=500);
		virtual bool getState();

	protected:
		int pin;
		bool pressedValue;
		bool checkPress(int timeout, bool requiredState);

};

class ButtonGroup{
	public:
		ButtonGroup();
		void begin(int length, int buttons[], bool pressedValue=HIGH);
		int pressed(int timeout=0);
	private:
		int buttons[BUTTONGROUP_LENGTH];
		//bool iStarted[BUTTONGROUP_LENGTH];
		int buttonsCount;
		bool pressedValue;

		int checkPress(int timeout, bool requiredState);
};

class LDR : public Button{
	public:
		LDR(int pin=A1);
		void config(int baseValue,int threashold);
		virtual bool getState();
		void test();
		void calibrate(int t=5000);
		void showConfig();

	protected:
		int base;
		int threashold;

};
/*
class TiltSwitch : public Button{
	public:
		TiltSwitch(int pin, bool pressedValue=LOW);
};
*/
/*
class CapacitiveSwitch : public Button{
	public:
		CapacitiveSwitch(int pin_in=13, int pin=12);
		void config(int threashold);
		void test();
		long getValue(int min=0);
		virtual bool getState();

	protected:
		CapacitiveSensor sensor;
		int threashold;
};
*/
class LED{
	//Mostly for the LED component in Tinkerkit
	public:
		LED(int pin=9);
		void begin();
		void on();
		void off();
		void blink(int speed,int times=1);
	private:
		int pin;
};
/*
class PiezoKnockSensor{
	public:
		PiezoKnockSensor(int pin=A0);
		void config(int threshold=40,int debounceTime=80);
		bool knocked(int timeout=0);
		void test();
	private:
		int pin;
		int threshold;
		long debounceTime;
};
*/
/*
class Player{
    public:
        Player();
        void begin();
        void play(char* name);

    private:
        void initPlayer();
        void initSD();
        void printDirectory(File dir, int numTabs);
        File root;
        char* name;
    };
*/
/*
class Knob{
	public:
		Knob(int pin);
		int getValue();
		void setLevels(int levels);
		int getLevel();
	private:
		int pin;
		int levels;
};
*/
/*
class Joystick{
    public:
        Joystick(int x, int y);
        int getX();
        int getY();
    private:
        int x;
        int y;
    };
*/
class Wheels{
    public:
        Wheels(int lpin=10, int rpin=9);
        void begin();
        void goForward();
        void goBackwards();
        void turnLeft();
        void turnRight();
        void standStill();
        void follow(int d);
    private:
        int top, low, still;
        void go(int tl, int tr);
        int lpin, rpin;
        Servo left, right;
        int fromL, fromR;
        int toL, toR;
        int tl, tr;
    };
#define KP 30
#define KD 7
#define LINE_THRESSHOLD 30
#define ROBOT_SPEED 50 //In % [0..100]
#define INTEGRATION_TIME 10

class IRArray{
    public:
        IRArray(int IR1=A1, int IR2=A2, int IR3=A3);
        void begin();
        void test();
		void setThreshold(int t);
        int readBinary();
        int readLine();
    private:
        int IR1, IR2, IR3;
        int sensPins[3];
        int sensorVal[3];
        int toBinary[3];
        int translateBinary();
        int calculateVelocity(int s);
        int last_diff;
		int threshold;

};
/*
class UltrasonicSensor{
    public:
        UltrasonicSensor(int trig=11, int echo=12);
		int getDistance();
    private:
		int trig, echo;
};
*/

#endif
