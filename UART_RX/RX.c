/*
 * RX.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

/*
 * RX.C
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */
/*
 //this uart  with polling recive 'a'

#include <avr/io.h>
#include <util/delay.h>


void UART_init(){

	UCSRA |=(1<<U2X);
	UCSRB |=(1<<RXEN);
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
	DDRB |=(1<<PB0);
	PORTB &=~(1<<PB0);
	_delay_ms(50);

	char buff;
	while(1){
		buff =UART_reciveByte();
		if(buff == 'A'){
			PORTB |=(1<<PB0);
		}
		}

	return 0;
}
*/

//uart by interrupt for recive 'A'
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


volatile char buff;
ISR(USART_RXC_vect){
	buff =UDR;
	if(buff == 'A'){
		PORTB |=(1<<PB0);
	}
}


void UART_init(){

	UCSRA |=(1<<U2X);
	UCSRB |=(1<<RXEN) |(1<<RXCIE);
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
	DDRB |=(1<<PB0);
	PORTB &=~(1<<PB0);
	_delay_ms(50);


	while(1){

		}

	return 0;
}
