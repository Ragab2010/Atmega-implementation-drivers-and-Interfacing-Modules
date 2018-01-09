/*
 * main.c
 *
 *  Created on: ٢٢‏/٠٤‏/٢٠١٧
 *      Author: RAGAB
 */

#include <avr/io.h>


void TIMER0_DELAY(){

	//TCNT0=192;
	OCR0 =255;
	TCCR0 = (1<<FOC0)|(1<<CS00)|(1<<CS02)|(1<<COM00);
	while(TIFR &(1<<TIFR)){
		TIFR |=(1<<TIFR);
	}
}
int main(){

	DDRB  |=(1<<PB3);
	PORTB =0x00;
	TIMER0_DELAY();
	for(;;){

		PORTB ^=(1<<PB0);
	}

	return 0;
}
