/*
 * master.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */


#include "avr/io.h"
#include "util/delay.h"
#define ACK 0X05

#define START 0X0F
#define STOP  'T'

void SPI_initMaster(){
	DDRB |=(1<<PB4)|(1<<PB5)|(1<<PB7);
	DDRB &=~(1<<PB6);
	SPCR =(1<<SPE)|(1<<MSTR)| (1<<SPR1) |(1<<SPR0);
	PORTB |=(1<<PB4);
}

void SPI_initSlave(){
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR =(1<<SPE);
}

unsigned char  spi_tranceiver (unsigned char data)
{
	SPDR=data;
	PORTB &=~(1<<PB4);
	while(!(SPSR & (1<<SPIF)));
	data =  SPDR;
	PORTB |=(1<<PB4);
	return data;

}
void SPI_sendByte(unsigned char byte){


	SPDR = byte;
	PORTB &=~(1<<PB4);
	while(!(SPSR & (1<<SPIF)));
	PORTB |=(1<<PB4);
}
unsigned char SPI_recieveByte(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;

}


int main(){
	SPI_initMaster();
	 DDRC =0xff;
	 PORTC =0X00;
	unsigned char data;
	unsigned char flag;
	_delay_ms(100);
	data = spi_tranceiver(START);


	while(1){
			if(PIND & (1<<PD0)){
				_delay_ms(20);
			if((PIND & (1<<PD0))&&flag == 0){
				flag=1;
				spi_tranceiver(0X01);
			}
			}
			else if(PIND & (1<<PD1)){
				_delay_ms(20);
			if((PIND & (1<<PD1))&&flag == 0){
				flag=1;
				spi_tranceiver(0X02);
			}
			}
			else{
				flag =0;
			}

		}


	return 0;
}
