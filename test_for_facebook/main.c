
#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#define ACK 5

#define START 'S'


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
uint8_t spi_tranceiver (uint8_t data)
{
	SPDR=data;
	while(!(SPSR)&(1<<SPIF));
	return SPDR;
}

int main(void)
{
    SPI_initSalve();
	 DDRC = 0x00;                                 //Initialize PORTA as INPUT
	 PORTC = 0xFF;
	 unsigned char data;


    /* Replace with your application code */
   while (1)
   {		do{

	   data = spi_tranceiver(ACK);   //send ack recive data

   }
   while(data != START);

   if (PINC==0)
   {
	   spi_tranceiver('A');
	   _delay_ms(1000);
   }
   if (PINC==1)
   {
	   spi_tranceiver('B');
	   _delay_ms(1000);
}
}
}
