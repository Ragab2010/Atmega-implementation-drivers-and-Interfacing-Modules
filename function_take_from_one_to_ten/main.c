/*
 * main.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠١٧
 *      Author: RAGAB
 */

#include <avr/io.h>


void timer1_dutycycle_old(float  num ){
	num /=10;
	unsigned short num_on= (num * 10000);
	//OCR1A=9777;
	OCR1AH=0X27;
	OCR1AL=0X0F;
	//OCR1BH=(num_on>>8);
	//OCR1BL=(num_on);
	OCR1B =num_on;
	TCNT1 =0x00;


}

void timer1_dutycycle_init(){
	DDRD |=(1<<PD5);
	TCCR1A =(1<<COM1A0  | 1<<WGM12 | 1<<FOC1A);
	TCCR1B =(1<<CS10);
}

void timer1_dutycycle(float  num){
	num /=10;
	unsigned short num_on= (unsigned short)(num * 10000);


}


int main(){


	timer1_dutycycle_init();

	float  num=1;
	num /=10;
	unsigned short num_on= 1000;//(unsigned short)(num * 10000);


	unsigned short compar_register_val[2]={num_on , 9999-num_on};
	unsigned char index=0;
	TCNT1 =0x00;
	while(1){
			while(!(TIFR &(1<<OCF1A)));
			while(TIFR &(1<<OCF1A)){
				OCR1A = compar_register_val[index++];
				TIFR |=(1<<OCF1A);
				if(index >2)
					index=0;
			}

	}
//	while(1){
//		while(flage ==1 ){
//			if(TIFR &(1<<OCF1B)){
//				PORTB ^=(1<<PB0);
//				TIFR |=(1<<OCF1B);
//				flage=0;
//			}
//		}
//		while(flage ==0){
//			if(TIFR &(1<<OCF1A)){
//				PORTB &=~(1<<PB0);
//				TIFR ^=(1<<OCF1A);
//				TCNT1 =0x00;
//				flage =1;
//			}
//		}
//	}



	return 0;
}
