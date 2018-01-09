/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "avr/io.h"
#include "util/delay.h"

void UART_init(){
	UCSRA |= (1<<U2X);
	UCSRB |=(1<<TXEN);
	UCSRC |=(1<<URSEL) |(1<<UCSZ0) | (1<<UCSZ1);
	UBRRL =103;

}

void UART_sendByte( char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}


int main(){

	UART_init();
	char *m="welcome";

	while(1)
	{
		_delay_ms(4000);
		while(*m){
			UART_sendByte(*m++);
			_delay_ms(50);
		}
		break;
	}

}
