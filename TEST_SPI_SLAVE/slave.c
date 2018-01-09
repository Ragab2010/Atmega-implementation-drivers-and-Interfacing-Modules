/*
 * slave.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */




#include "avr/io.h"


#define ACK 0X05

#define START 0X0F
#define STOP  'T'

void SPI_initMaster(){
	DDRB |=(1<<PB4)|(1<<PB5)|(1<<PB7);
	DDRB &=~(1<<PB6);
	SPCR =(1<<SPE)|(1<<MSTR)| (1<<SPR1) |(1<<SPR0);
}

void SPI_initSlave(){
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR =(1<<SPE);
}

unsigned char  spi_tranceiver (unsigned char data)
{

	SPDR=data;
	while(!(SPSR)&(1<<SPIF));
	while(!(PINB & (1<<PB4)));
	return SPDR;
}
void SPI_sendByte(unsigned char byte){
	SPDR = byte;
	while(!(SPSR & (1<<SPIF)));
}
unsigned char SPI_recieveByte(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;

}


int main(){
	SPI_initSlave();
	 DDRC =0xff;
	 PORTC =0X00;
	unsigned char data=0x00;

	while(1){


		data =spi_tranceiver(ACK);
		PORTC = data;

	}


	return 0;
}
