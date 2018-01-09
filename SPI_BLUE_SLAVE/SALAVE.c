/*
 * SALAVE.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include <avr/io.h>
#include <util/delay.h>

#define ACK 0X05

#define START 'S'
#define STOP  'T'

#define MOTOR1_FORWOARD 'A'
#define MOTOR1_REVERSE 'B'

void SPI_initMaster()
{
	DDRB |=(1<<PB4)|(1<<PB5)|(1<<PB7);
	DDRB &=~(1<<PB6);
	SPCR |=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);
}
void SPI_initSalve()
{
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR |=(1<<SPE);
}
unsigned char SPI_reciveByte( )
{

	//SPDR=data;
	while(!(SPSR)&(1<<SPIF));
	return SPDR;
}

int main(void)
{
	SPI_initSalve();
	DDRC=0xFF;
	DDRD=0xFF;
	PORTC = 0X00;
	PORTD = 0X00;

	unsigned char data;
	unsigned char flag=0;


	_delay_ms(1000);
	/* Replace with your application code */

	while(1){

		data =SPI_reciveByte();

		if(data == START){
				PORTD =0x0f;
		}

		if (data == MOTOR1_FORWOARD && flag==0 )
		{
			flag=1;
			PORTC =(1<<PC0);
			_delay_ms(3000);
			PORTC =0x00;
		}
		if(data == MOTOR1_REVERSE&& flag==1 )
		{
			flag=0;
			PORTC =(1<<PC1);
			_delay_ms(3000);
			PORTC =0x00;
		}
	}
}

