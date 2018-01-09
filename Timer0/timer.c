/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include <avr/io.h>

void Timer0_delay(){
	volatile unsigned int i=0;
	TCCR0 =(1<<FOC0) | (1<<CS00);
	TCNT0 = 0;
	while(i < 62500){
		while((TIFR &(1<<TOV0))){
			TIFR |=(1<<TOV0);
			i++;
		}
	}


}

int main(){
	DDRB |=(1<<PC0);
	PORTB &=~(1<<PC0);

	while(1){
		PORTB ^=(1<<PC0);
		Timer0_delay();
	}

}
