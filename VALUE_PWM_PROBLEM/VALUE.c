/*
 * VALUE.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "avr/io.h"
#include "avr/interrupt.h"
/*
 CRYSTAL = 1MHZ
 Prescaller = 8
 Normal mode timer0
 and it take 0.002Sec to overflow

 */
/*-------NUMBER OF OVERFLOW FOR EVERY PWM----------*/
#define PA0_ON 50
#define PA0_OFF 50

#define PA1_ON 7
#define PA1_OFF 3


#define PA2_ON 4
#define PA2_OFF 1
#define PA2_OFF_PROB 5
/*-----------------*/
volatile char N_OVERFLOW_PA0=0;
volatile char N_OVERFLOW_PA1=0;
volatile char N_OVERFLOW_PA2=0;

volatile char ON_FRIST_RA1=0;
volatile char ON_FRIST_RA2=0;


ISR(TIMER0_OVF_vect){

	TIFR |=(1<<TOV0);//clear overflow flage

	++N_OVERFLOW_PA0;
	++N_OVERFLOW_PA1;
	++N_OVERFLOW_PA2;
//
//	if(N_OVERFLOW_PA0 == PA0_ON ){ //ON -OFF ARE EQUAL 50 OVERFLOW
//		N_OVERFLOW_PA0=0;
//		PORTA ^=(1<<PA0);
//	}
//	/*
//	 here we found problem . that number of overflow of OFF less than ONN
//	 .so the condition of OFF always executes frist
//	 solve:
//	 1-make Flage
//	 2-sum the time of ONN with OFF
//	 ----------
//	 use method 1
//	 */
//	if((N_OVERFLOW_PA1 == PA1_ON) && ON_FRIST ==0 ){
//		N_OVERFLOW_PA1=0;
//		ON_FRIST =1;
//		PORTA ^=(1<<PA1);
//	}else if((N_OVERFLOW_PA1 == PA1_OFF) && ON_FRIST ==1){
//		N_OVERFLOW_PA1=0;
//		ON_FRIST =0;
//		PORTA ^=(1<<PA1);
//	}
//	/*
//	 same problem
//	 --------
//	 but here will use method 2
//	 */
//
//	if(N_OVERFLOW_PA2 == PA2_ON){
//		//N_OVERFLOW_PA2=0; //will make OFF  make N_OVERFLOW_PA2 =0 after finishing cycle
//		PORTA ^=(1<<PA2);
//	}else if(N_OVERFLOW_PA2 == PA2_OFF_PROB){
//		N_OVERFLOW_PA2=0;
//		PORTA ^=(1<<PA2);
//	}
//





}
void timer0_init_interrupt(){
	TCCR0 |=(1<<FOC0) |(1<<CS01) ;
	TIMSK |=(1<<TOIE0);
	sei();

}


int main(){

	DDRA |=(1<<PA0)|(1<<PA1)|(1<<PA2);//MAKE PA0 PA1 PA2 AS output
	PORTA |=(1<<PA0)|(1<<PA1)|(1<<PA2);//MAKE VOLT ON  PA0 PA1 PA2 ZERO VOLT

	timer0_init_interrupt();

	while(1){

		if(N_OVERFLOW_PA0 == PA0_ON ){ //ON -OFF ARE EQUAL 50 OVERFLOW
			N_OVERFLOW_PA0=0;
			PORTA ^=(1<<PA0);
		}
		/*
		 here we found problem . that number of overflow of OFF less than ONN
		 .so the condition of OFF always executes frist
		 solve:
		 1-make Flage
		 2-sum the time of ONN with OFF
		 ----------
		 use method 1
		 */
		if((N_OVERFLOW_PA1 == PA1_ON) && ON_FRIST_RA1 ==0 ){
			N_OVERFLOW_PA1=0;
			ON_FRIST_RA1 =1;
			PORTA ^=(1<<PA1);
		}else if((N_OVERFLOW_PA1 == PA1_OFF) && ON_FRIST_RA1 ==1){
			N_OVERFLOW_PA1=0;
			ON_FRIST_RA1 =0;
			PORTA ^=(1<<PA1);
		}
		/*
		 same problem
		 --------
		 but here will use method 1
		 */

		if((N_OVERFLOW_PA2 == PA2_ON) && ON_FRIST_RA2  == 0){
			N_OVERFLOW_PA2=0;
			ON_FRIST_RA2 = 1;
			PORTA ^=(1<<PA2);
		}else if((N_OVERFLOW_PA2 == PA2_OFF) && ON_FRIST_RA2 == 1){
			N_OVERFLOW_PA2=0;
			ON_FRIST_RA2 = 0;
			PORTA ^=(1<<PA2);
		}


	}

	return 0;
}


