/*
 * adc.c
 *
 *  Created on: ٢٧‏/٠٦‏/٢٠١٧
 *      Author: RAGAB
 */

#include <avr/io.h>
#include "util/delay.h"
#include "lcdlib.h"

#define VREF 5

void ADC_init(){
	/*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
	ADMUX |=(1<<REFS0) ;
	/* ADC Enable*/
	ADCSRA |=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);
}

unsigned short ADC_read(unsigned char ch){
	ch &=0x07;
	DDRA &=~(1<<ch);
	ADMUX |= ch ;
	ADCSRA |=(1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)) );
	ADCSRA |=(1<<ADIF);
	return ADC;
}



void PWM_init_phaseCorrect(){
	DDRB |=(1<<PB3);
	OCR0 =0;
	TCCR0 =(1<<WGM00)|(1<<COM01)|(1<<CS00);
}

void PWM_init_fastPwm(){
	DDRB |=(1<<PB3);
	OCR0 =0;
	TCCR0 =(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}

void adc_to_pwmbyPhaseCorrect(float inputVolt ){
	float duty= (inputVolt/VREF)*100;
	unsigned char ocr = ((duty*255)/100);
	OCR0 =ocr;
	LCD_goToRowCol(1,11);
	LCD_intToString(ocr);


}
void adc_to_pwmbyFastPwm(float inputVolt){
		float duty= (inputVolt/VREF)*100;
		unsigned char ocr;
		if(duty==0){
			ocr =0;
		}else{
			ocr = ((duty*256)/100)-1;
		}
		OCR0 =ocr;
		LCD_goToRowCol(1,11);
		LCD_intToString(ocr);


}

int main(){

	LCD_init();
	ADC_init();
	//PWM_init_fastPwm();
	PWM_init_phaseCorrect();
	DDRB = 0XFF;
	PORTB=0X00;
	float  rest;
	float vo;
	while(1){
		LCD_goToRowCol(1,1);
		rest =ADC_read(0);
		vo =(rest * 5)/1024;
		LCD_intToString(vo*100);
		/*output the volt by pwm*/
		//adc_to_pwmbyFastPwm(vo);
		adc_to_pwmbyPhaseCorrect(vo);

	}

	return 0;
}
