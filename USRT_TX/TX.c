/*
 * TX.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include <avr/io.h>
#include <util/delay.h>
/*
 * syn mode - 1MHZ -boudrate=9600bps
 */


void UART_init(){

	//UCSRA |=(1<<U2X); //we use syn mode
	UCSRB |=(1<<TXEN);
	UCSRC |=(1<<UMSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRH |=(1<<URSEL);
	UBRRL =52;

	DDRB |=(1<<PB0);
}

void UART_sendByte(char byte){
	while(!(UCSRA &(1<<UDRE)));
	UDR = byte;
}

char UART_reciveByte(){
	while(!(UCSRA &(1<<RXC)));
	return UDR;

}

int main(){
	UART_init();
	_delay_ms(50);
	UART_sendByte('A');

	while(1){

	}

	return 0;
}


