#ifndef Castilla_h
#define Castilla_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "../CapacitiveSensor/CapacitiveSensor.h"
#include "../Servo/Servo.h"


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
		/*
		void setMelody(int lendgth, int notes[],int duration[]);*/
		void play(int length, int notes[],int diration[], float speed=1.3);
		void beep(int note=20, int length=30);
		void playTone(int note, int length=10);
		/*
		void setNote(int index,int note);
		int getNote(int index);
		void setDuration(int index,int duration);
		int getDuration(int index);*/
	private:
		int pin;
		/*
		int length;
		int notes[LENGTH];
		int duration[LENGTH];
		*/

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

		//bool pressed(int timeout=0);
		//bool released(int timeout=0);
		//bool doublePressed(int timeout=0,int tolerance=500);

	protected:
		int base;
		int threashold;

};

class TiltSwitch : public Button{
	public:
		TiltSwitch(int pin, bool pressedValue=LOW);
};

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

class ContinuousServo{
    public:
        ContinuousServo(int pin=9, bool direction=true);
        void begin(int stillSpeed=97);
        void goForward(int speed=100);
        void goBackwards(int speed=100);
        void standStill();
        void setSpeed(int speed);

    private:
        int pin;
        int speed;
		int stillSpeed;
		bool direction;
        Servo servo;

		void go(int speed, bool goDirection);
};

class Joystick{
    public:
        Joystick(int x, int y);
        int getX();
        int getY();
    private:
        int x;
        int y;
    };
#endif
