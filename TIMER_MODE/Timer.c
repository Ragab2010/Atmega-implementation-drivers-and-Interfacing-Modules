/*
 * Timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "avr/io.h"


void timer0_init(){
	DDRB |=(1<<PB3);
	TCCR0 =(1<<FOC0)|(1<<COM00)|(1<<CS01)|(1<<WGM01);


}


int main(){
	DDRB |=(1<<PB2);
	timer0_init();
	char i=0;
	while(1){
		if(TIFR & (1<<TOV0)){
			PORTB ^=(1<<PB2);
			TIFR |=(1<<TOV0);

		}
		if((TIFR & (1<<OCF0)) && i == 0){
			TIFR |=(1<<OCF0);
			OCR0 = 100;
			i=1;
		}
		else if((TIFR & (1<<OCF0)) && i == 1){
					TIFR |=(1<<OCF0);
					OCR0 = 250;
					i=0;
		}

	}

	return 0;
}
