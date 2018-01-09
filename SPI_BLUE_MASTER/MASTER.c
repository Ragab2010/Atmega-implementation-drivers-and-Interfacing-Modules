///*
// * MASTER.c
// *
// *  Created on: ??�/??�/????
// *      Author: RAGAB
// */
//
//
//#include <avr/io.h>
//#include <util/delay.h>
//#define ACK 0X05
//
//#define START 'S'
//#define STOP  'T'
//
//#define MOTOR1_FORWOARD 'A'
//#define MOTOR1_REVERSE 'B'
//
//void SPI_initMaster(){
//	DDRB |=(1<<PB4)|(1<<PB5)|(1<<PB7);
//	DDRB &=~(1<<PB6);
//	SPCR =(1<<SPE)|(1<<MSTR)| (1<<SPR1) |(1<<SPR0);
//	PORTB |=(1<<PB4);
//}
//
//void SPI_initSalve()
//{
//	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
//	DDRB |=(1<<PB6);
//	SPCR |=(1<<SPE);
//}
//unsigned char  spi_tranceiver (unsigned char data)
//{
//	PORTB &=~(1<<PB4);
//	SPDR=data;
//	while(!(SPSR & (1<<SPIF)));
//	data = SPDR;
//	PORTB |=(1<<PB4);
//	return data;
//
//}
//
//int main(void)
//{
//    SPI_initMaster();
//	DDRC = 0x00;                                 //Initialize PORTA as INPUT
//
//	 unsigned char data;
//	 unsigned char q=0;
//
//    /* Replace with your application code */
//
//
//	   data = spi_tranceiver(START);   //send start recive data
//
//
//
//
//   while (1)
//   {
//
//	   if ((PINC &(1<<PC0)))
//	     {
//	  	 	 if(q==0){
//	  	 		 spi_tranceiver(MOTOR1_FORWOARD);
//	  	 		 q=1;
//	  	 	 }else{
//	  	 		 spi_tranceiver(MOTOR1_REVERSE);
//	  	 		 q=0;
//	  	 	 }
//	  	 	 while((PINC &(1<<PC0)));
//	     }
//
//
//
//   }
//}


#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#define ACK 0X05

#define START 'S'
#define STOP  'T'

#define MOTOR1_FORWOARD 'A'
#define MOTOR1_REVERSE 'B'

void SPI_initMaster(){
	DDRB |=(1<<PB4)|(1<<PB5)|(1<<PB7);
	DDRB &=~(1<<PB6);
	SPCR |=(1<<SPE)|(1<<MSTR);
}
void SPI_initSalve(){
	DDRB &=~((1<<PB4)|(1<<PB5)|(1<<PB7));
	DDRB |=(1<<PB6);
	SPCR |=(1<<SPE);
}


unsigned char  spi_tranceiver (unsigned char data)
{

	SPDR=data;
	while(!(SPSR & (1<<SPIF)));

	return data;

}

int main(void)
{
	SPI_initMaster();
	DDRC = 0x00;                                 //Initialize PORTA as INPUT

	//unsigned char data;
	unsigned char q=0;

	/* Replace with your application code */


	spi_tranceiver(START);   //send start recive data




	while (1)
	{

		if ((PINC &(1<<PC0)))
		{
			if(q==0){
				spi_tranceiver(MOTOR1_FORWOARD);
				q=1;
				}
				else{
				spi_tranceiver(MOTOR1_REVERSE);
				q=0;
			}
			while((PINC &(1<<PC0)));
		}



	}
}


