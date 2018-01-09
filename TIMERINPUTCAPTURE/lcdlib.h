/*
 * lcdlib.h
 *
 *  Created on: ٢٤‏/٠٤‏/٢٠١٧
 *      Author: RAGAB
 */

#ifndef LCDLIB_H_
#define LCDLIB_H_

#include <avr/io.h>
#include "avr/delay.h"
#include <stdlib.h>


#define RS PD0
#define RW PD1
#define E  PD2
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

void LCD_init();
void LCD_command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_displayString(unsigned char *str );
void LCD_displayCharacter(unsigned char Byte );
void LCD_intToString(unsigned short data);
void LCD_clearScreen(void);
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str );


void LCD_init(){
	LCD_CTRL_PORT_DIR |=(1<<RS) |(1<<RW) |(1<<E);
	LCD_DATA_PORT_DIR = 0XFF;
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x01);



}
void storeShape(unsigned char row , unsigned char col  ){
	unsigned char i,shape[8]= {0,0,10,31,31,14,4,0};
	LCD_command(0x40);//set adress pointer to point on adress 00000 in CGRAM
	for( i=0 ; i < 8  ; i++ ){
		LCD_Data(shape[i]);

	}
	LCD_goToRowCol(row , col);
	LCD_Data(0x00); // show the address this of CGRAM

}
void LCD_command(unsigned char command){
	LCD_CTRL_PORT &=~((1<<RS)|(1<<RW));
	_delay_ms(1);
	LCD_CTRL_PORT |=(1<<E);
	_delay_ms(1);
	LCD_DATA_PORT = command;
	_delay_ms(1);
	LCD_CTRL_PORT &=~(1<<E);
	_delay_ms(1);
}
void LCD_Data(unsigned char data){
	LCD_CTRL_PORT |=(1<<RS);
	LCD_CTRL_PORT &=~(1<<RW);
	_delay_ms(1);
	LCD_CTRL_PORT |=(1<<E);
	_delay_ms(1);
	LCD_DATA_PORT = data;
	_delay_ms(1);
	LCD_CTRL_PORT &=~(1<<E);
	_delay_ms(1);
}
void LCD_goToRowCol(unsigned char row ,unsigned char col ){
	unsigned char fristCharAddr[]={0x80 , 0XC0, 0X94 ,0XD4};
	LCD_command(fristCharAddr[row-1] + col-1);
	_delay_ms(1);

}
void LCD_displayCharacter(unsigned char Byte ){
	LCD_Data(Byte);
}

void LCD_displayString(unsigned char *str ){
	do{
		LCD_Data(*str++);
	}while(*str);
}
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str ){
	LCD_goToRowCol(row , col);
	LCD_displayString(str);
}
void LCD_clearScreen(void){
	LCD_command(0x01); //clear display
}
void LCD_intToString(unsigned short data){
	unsigned char buff[16]; /* String to hold the ascii result */
	// itoa(data,buff,10); /* 10 for decimal */
	sprintf(buff ,"%d",data);
	 LCD_displayString(buff);
}




#endif /* LCDLIB_H_ */
