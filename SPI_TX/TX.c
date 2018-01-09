/*
 * TX.c
 *
 *  Created on: ??�/??�/????
 *      Author: RAGAB
 */

#include <avr/io.h>
#include <util/delay.h>



void SPI_initMaster(){
	/*THER SS AUTO WITH SPI*/
	/*you have to make ss as ouput and then
	 * if you dont use it .. it will auto with spi module
	 * or you can make it low after translate  and
	 * before make it high*/
		DDRB |=(1<<PB5)|(1<<PB7)|(1<<PB4);
		DDRB &=~(1<<PB6);
		SPCR |= (1<<SPE)|(1<<MSTR);
		PORTB |=(1<<PB4); //if you use ss manuale



}


void SPI_initSlave(){
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR |=(1<<SPE);
}

void SPI_sendByte(unsigned char byte){
	PORTB &=~(1<<PB4);//before translate make it low
	SPDR = byte;

	while(!(SPSR & (1<<SPIF)));
	PORTB |=(1<<PB4);//after translate make it high

}


unsigned char SPI_reciveByte(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;

}


int main(){
	SPI_initMaster();
	_delay_ms(50);
	SPI_sendByte(0x03);
	SPI_sendByte(0xff);
	while(1){

	}

	return 0;
}

