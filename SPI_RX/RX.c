/*
 * RX.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */


#include <avr/io.h>
#include <util/delay.h>


void SPI_initMaster(){
	/*THER SS AUTO WITH SPI*/
	DDRB |=(1<<PB5)|(1<<PB7)|(1<<PB4);
	DDRB &=~(1<<PB6);
	SPCR |= (1<<SPE)|(1<<MSTR);
	/*THER SS NOT AUTO WITH SPI*/
//	DDRB |=(1<<PB5)|(1<<PB7)|(1<<PB4);
//	DDRB &=~(1<<PB6);
//	SPCR |= (1<<SPE);
//	PORTB |=(1<<PB4);

}

void SPI_initSlave(){
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR |=(1<<SPE);
}

void SPI_sendByte(unsigned char byte){
	SPDR = byte;
	while(!(SPSR & (1<<SPIF)));


}


unsigned char SPI_reciveByte(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;

}


int main(){
	SPI_initSlave();
	DDRA =0xff;
	PORTA = 0X00;
	_delay_ms(10);
	unsigned char x;
	while(1){
		x = SPI_reciveByte();
			PORTA = x;
	}

	return 0;
}

