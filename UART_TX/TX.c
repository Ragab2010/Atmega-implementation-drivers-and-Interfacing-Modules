/*
 * TX.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */
/*
//this uart by polling  Send 'A'
#include <avr/io.h>
#include <util/delay.h>


void UART_init(){

	UCSRA |=(1<<U2X);
	UCSRB |=(1<<TXEN);
	UCSRC |=(1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL =103;
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

*/

//this uart by interrupt  Send 'A'
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(USART_UDRE_vect ){
	UDR = 'A';
}

void UART_init(){

	UCSRA |=(1<<U2X);
	UCSRB |=(1<<TXEN)|(1<<UDRIE);
	UCSRC |=(1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL =103;
	sei();
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


	while(1){

	}

	return 0;
}
