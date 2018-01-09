/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "avr/io.h"

void TIMER1_init_overFlow(){
	DDRD |=(1<<PD4) |(1<<PD5);
	OCR1A =100;
	OCR1B =100;
	TCCR1A |=(1<<COM1A0)|(1<<COM1B0);
	TCCR1B |=(1<<CS10)|(1<<WGM12);

}


int main(){
	TIMER1_init_overFlow();

	while(1);
	return 0;
}
