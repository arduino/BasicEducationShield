#include "Castilla.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Melody::Melody(int pin){
	this->pin=pin;
	/*
	for(int i=0;i<LENGTH;i++){
		notes[i]=-1;
		duration[i]=0;
	}*/
}
void Melody::play(int length, int notes[],int duration[],float speed){
	//Play the melody passed directly to this function. Saving memory
	//and avoiding variable scope problems.
	//length is the number of notes.
	//speed is a float bigger than 1. The bigger it is, the slower 
	//sound it makes.
	for(int i=0;i<length && notes[i]!=-1 ;i++){
		tone(pin,notes[i],1000/duration[i]);
		int pauseBetweenNotes = 1000/duration[i]*speed;
		delay(pauseBetweenNotes);
		noTone(8);
	}
}
void Melody::beep(int note, int length){
	//Make a beep sound
	int notes[]={note};
	int duration[]={1000/length};
	play(1,notes,duration,1);
}
void Melody::playTone(int note,int length){
	//Play a certain tone. Much more flexible than defined notes.
	tone(pin,note,length+5);
	delay(length);
}

/*
void Melody::setMelody(int length, int notes[],int duration[]){
	this->length=length;
	for(int i=0;i<length;i++){
		this->notes[i]=notes[i];
		this->duration[i]=1000/duration[i];
	}
}

void Melody::play(){
	for(int i=0;i<length && notes[i]!=-1 ;i++){
		Serial.print(notes[i]);
		Serial.print("\t");
		Serial.println(duration[i]);
		
		tone(pin,notes[i],duration[i]);
		int pauseBetweenNotes = duration[i];
		delay(pauseBetweenNotes);
		noTone(8);
	}
}

void Melody::setNote(int index,int note){
	notes[index]=note;
}
int Melody::getNote(int index){
	return notes[index];
}
void Melody::setDuration(int index, int duration){
	this->duration[index]=duration;
}
int Melody::getDuration(int index){
	return duration[index];
}
*/
