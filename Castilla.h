#ifndef Castilla_h#define Castilla_h#if ARDUINO >= 100#include "Arduino.h"#else#include "WProgram.h"#endif#define LED_LENGTH 20class VUMeter{	public:		VUMeter();		void config(int length, int pins[]);		void initialize();		void on(int index);		void off(int index);		void scrollLeft(int speed,int startIndex=0);		void scrollRight(int speed,int startIndex=0);		void fill(int length);		void fillFrom(int leftIndex,int rightIndex);		void blink(int index, int speed, int times=1);		void blinkAll(int speed,int times=1);		void clear();				void test();	private:		void blinkOnce(int index,int onTime,int offTime);		//int getPin(int index);		int pins[LED_LENGTH];		int pinCount;};#define MELODY_LENGTH 32class Melody{	public:		Melody(int pin);		/*		void setMelody(int lendgth, int notes[],int duration[]);*/		void play(int length, int notes[],int diration[], float speed=1.3);		/*		void setNote(int index,int note);		int getNote(int index);		void setDuration(int index,int duration);		int getDuration(int index);*/	private:		int pin;		/*		int length;		int notes[LENGTH];		int duration[LENGTH];		*/		};class Button{	public:		Button(int pin=8,bool pressedValue=HIGH);		void initialize();		bool pressed(int timeout=0);		bool released(int timeout=0);		bool doublePressed(int timeout=0,int tolerance=500);	protected:		int pin;		bool pressedValue;				bool getState();		bool checkPress(int timeout, bool requiredState);};class LDR : public Button{	public:		LDR(int pin=A1);		void config(int baseValue,int threashold);		void test();				//bool pressed(int timeout=0);		//bool released(int timeout=0);		//bool doublePressed(int timeout=0,int tolerance=500);			protected:		int base;		int threashold;				bool getState();};#endif