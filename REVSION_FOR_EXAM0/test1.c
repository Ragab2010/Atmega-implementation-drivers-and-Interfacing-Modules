/*
 * test1.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠١٧
 *      Author: RAGAB
 */


#include <avr/io.h>

void timer0_init_pwm(){
	DDRB = 1<<PB3 ;
	TCCR0 = 1<<COM00 | 1<<CS00;
	OCR0 = 63;
}

int main(){
	timer0_init_pwm();

	while(1);

	return 0;
}
