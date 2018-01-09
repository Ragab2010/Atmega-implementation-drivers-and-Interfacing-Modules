/*
 * PWM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */
#include "avr/io.h"

void TIMER0_init_pwm(unsigned char duty_cycle){
	/* using non-inverted mode, Write a program that generates a
		wave with frequency of 31,250 Hz and duty cycle of75%.-
		31.250HZ = (8*10^6)/(N * 256)  then N=1 no prescaller
	*/
	DDRB |=(1<<PB3);
	OCR0 = duty_cycle;
	TCCR0  =(1<<WGM01) |(1<<WGM00)|(1<<COM01)|(1<<CS00);

}
void TIMER0_init_pwm_phaseCorrect(unsigned char duty_cycle){
	/* using non-inverted.mode, Write api:o~ ~t geeerates a
		wave with frequency of 15.,686Hz and
		duty cycle Of 75%  then N=1 no prescaller
	*/
	DDRB |=(1<<PB3);
	OCR0 = duty_cycle;
	TCCR0  =(1<<WGM00) |(1<<COM01)|(1<<COM00)|(1<<CS00); //|(1<<WGM01)

}


int main(){

	TIMER0_init_pwm(0); // 75% equal to  ((75*256)-1)/100  =191

	//TIMER0_init_pwm_phaseCorrect(0);//75% equal to  191

	while(1);
	return 0;
}

