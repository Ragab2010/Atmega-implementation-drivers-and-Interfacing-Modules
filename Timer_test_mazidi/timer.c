/*
 * timer.c
 *
 *  Created on: ٢٢‏/٠٦‏/٢٠١٧
 *      Author: RAGAB
 */

#include <avr/io.h>
#define NUMBER_OF_OVERFLOW 2
volatile unsigned int dutycycle = 0;


 void timer0_init(){
	 TCCR0 =(1<<FOC0)|(1<<CS01)|(1<<COM00);
	 OCR0 =128;

 }

 void timer1_pwn(unsigned short dutycycle){
	 DDRD |=(1<<PD5);
	 OCR1A = dutycycle;
	 TCCR1A = (1<<COM1A1) |(1<<WGM10)|(1<<WGM11) |(1<<WGM12);
	 TCCR1B = (1<<CS10);
 }


int main(){

	DDRD =0XFF;
	DDRC =0X00;
	PORTD =0X00;


	while(1){

		while(!(PINC &(1<<PC0)))
		{
			PORTD++;
			while(!(PINC &(1<<PC0)));
		}
	}

	return 0;
}
