#include<reg51.h>
#define OFF 0
#define ON 1

sbit led=P2^0;
sbit posfivebut=P0^0;
sbit postenbut=P0^1;
sbit negtenbut=P0^2;
int buttonstate1=ON;
int previousbuttonstate1=ON;
int buttonstate2=ON;
int previousbuttonstate2=ON;
int buttonstate3=ON;
int previousbuttonstate3=ON;
int counter=0;
unsigned int i=0;
unsigned int j=0;

void delay()
	{
		TMOD = 0x01;    // Timer0 mode1
		TH0 = 0xFC; 	 //initial value for 1ms
		TL0 = 0x66;
		TR0 = 1;      // timer start
		while(TF0==0);  // check overflow condition
		TR0 = 0;     // Stop Timer
		TF0 = 0;    // Clear flag
	}

void onesecdelay(){
	for(i=0;i<1000;i++){
		delay();
	}
}
void check1();
void check2();
void check3();

void main(){
while(1){
check1();
check2();
check3();
	if(counter>0){
	led=OFF;
	}
	else{
	led=ON;
	}
	for(i=0;i<300*counter;i++){
		for(j=0;j<1000;j++){
			delay();
			check1();
			check2();
			check3();
			}
		}
	counter=0;
		
	}
}
	
void check1(){
	if(posfivebut==OFF){
	buttonstate1=OFF;
	}else{
	buttonstate1=ON;
	}
	if(previousbuttonstate1!=buttonstate1 & buttonstate1==ON){
	counter++;
	}
	previousbuttonstate1=buttonstate1;
}

void check2(){
	if(postenbut==OFF){
	buttonstate2=OFF;
	}else{
	buttonstate2=ON;
	}
	if(previousbuttonstate2!=buttonstate2 & buttonstate2==ON){
	counter=counter+2;
	}
	previousbuttonstate2=buttonstate2;
}

void check3(){
	if(negtenbut==OFF){
	buttonstate3=OFF;
	}else{
	buttonstate3=ON;
	}
	if(previousbuttonstate3!=buttonstate3 & buttonstate3==ON){
	counter=counter-2;
		if(counter<0){
		counter=0;
		}
	}
	previousbuttonstate3=buttonstate3;
}
