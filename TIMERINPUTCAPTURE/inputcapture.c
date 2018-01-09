/*
 * inputcapture.c
 *
 *  Created on: ٢٨‏/٠٦‏/٢٠١٧
 *      Author: RAGAB
 */

#include <avr/io.h>


#include "avr/delay.h"
#include <stdlib.h>
#include "lcdlib.h"

void timer1_inputcapture_init(){
	DDRD &=~(1<<PD6);
	TCCR1A =(1<<WGM12)|(1<<WGM13);
	TCCR1B =(1<<CS10);
}

unsigned short inputCapture(){

	while(!(TIFR & (1<<ICF1)));
	TIFR |= (1<<ICF1);
	return  ICR1;

}

int main(){
	LCD_init();
	timer1_inputcapture_init();
	unsigned short T ,P , B;
	while(1){
		T=inputCapture();
		B=inputCapture();
		P=T-B;
		LCD_goToRowCol(1,1);
		LCD_intToString(P);

	}


	return 0;
}
