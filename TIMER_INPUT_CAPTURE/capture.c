/*
 * capture.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

//
//#include "avr/io.h"
//
///*
//Assuming that clock pulses are fed into pin ICP1, write a program to read the TCNTI
//value on every rising edge. Place the result on PORTA and PORTB.
//
//*/
//void timer1_init(){
//	DDRD |=(1<<PD6);
//	TCCR1A =0X00;
//	TCCR1B =(1<<ICES1)|(1<<CS10);
//
//
//
//}
//
//
//int main(){
//
//	DDRA =0XFF;
//	DDRB=0XFF;
//	timer1_init();
//
//	while(1){
//
//		while(!(TIFR &(1<<ICF1)));
//		TIFR |=(1<<ICF1);
//		PORTA =ICR1L;
//		PORTB =ICR1H;
//
//	}
//
//
//	return 0;
//}


/*-------------------------------------------------------*/
//
//#include "avr/io.h"
///*
//Assuming that clock pulses are fed into pin PORTD.6, write a program to measure the
//period of the pulses. Place the binary result on PORTA and PORTB.
//
//*/
//
//
//void timer1_init(){
//	DDRD |=(1<<PD6);
//	TCCR1A =0X00;
//	TCCR1B =(1<<ICES1)|(1<<CS10);
//
//
//
//}
//
//
//int main(){
//
//	DDRA =0XFF;
//	DDRB=0XFF;
//	timer1_init();
//	unsigned int t;
//	while(1){
//
//		while(!(TIFR &(1<<ICF1)));
//		TIFR |=(1<<ICF1);
//		t=ICR1;
//		while(!(TIFR &(1<<ICF1)));
//		TIFR |=(1<<ICF1);
//		t=ICR1-t;
//		PORTA = t;
//		PORTB = t>>8;
//
//	}
//
//
//	return 0;
//}


/*------------------------------------------------------*/
/*
 Assume that a 60-Hz frequency pulse is connected to lepl (pin PD6). Write a program
to measure its pulse width. Use the prescaler value that gives the result ina single byte.
Display the result on PORTB. Assume XTAL = 8 MHz.
 */

#include "avr/io.h"


void timer1_init_rising(){

	TCCR1A =0X00;
	TCCR1B =(1<<ICES1)|(1<<CS10);
}
void timer1_init_falling(){

	TCCR1A =0X00;
	TCCR1B =(1<<CS10);
}


int main(){
	DDRD |=(1<<PD6); // the ICP1 PIN FOR INPUT CAPTURE
	DDRA =0XFF;
	DDRB=0XFF;
	unsigned int t;




		//calculate the rising of pulse
		timer1_init_rising();
		while(!(TIFR &(1<<ICF1)));
		TIFR |=(1<<ICF1);
		t=ICR1;

		//calculate the falling of pulse
		 timer1_init_falling();
		while(!(TIFR &(1<<ICF1)));
		TIFR |=(1<<ICF1);
		PORTA=ICR1-t;
		while(1);





	return 0;
}


