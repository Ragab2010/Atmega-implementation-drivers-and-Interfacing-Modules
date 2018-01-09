/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "avr/io.h"
#include "util/delay.h"
#include "KEYPAD.h"
#include <stdio.h>


#define LCD_DDR_DATA DDRC
#define LCD_PORT_DATA PORTC
#define LCD_DDR_CTRL DDRD
#define LCD_PORT_CTRL PORTD

#define RS PD0
#define RW PD1
#define E  PD2


void LCD_sendCommand(unsigned char comm){
	LCD_PORT_CTRL &=~((1<<RS)|(1<<RW));
	_delay_ms(1);
	LCD_PORT_CTRL |=(1<<E);
	_delay_ms(1);
	LCD_PORT_DATA =comm;
	_delay_ms(1);
	LCD_PORT_CTRL &=~(1<<E);
	_delay_ms(1);
}
void LCD_sendData(unsigned char Character){
	LCD_PORT_CTRL |=(1<<RS);
	LCD_PORT_CTRL &=~(1<<RW);
	_delay_ms(1);
	LCD_PORT_CTRL |=(1<<E);
	_delay_ms(1);
	LCD_PORT_DATA =Character;
	_delay_ms(1);
	LCD_PORT_CTRL &=~(1<<E);
	_delay_ms(1);
}
void LCD_displayCharacter(unsigned char ch){
	LCD_sendData(ch);
}

void LCD_goToRowCol(unsigned char row ,unsigned char col ){
	unsigned char fristCharAddr[]={0x80 , 0XC0, 0X94 ,0XD4};
	LCD_sendCommand(fristCharAddr[row -1] + (col -1));
	_delay_ms(1);
}

void LCD_displayString(const  unsigned char *ptr){
	unsigned char i=0;
	do{
		LCD_displayCharacter(ptr[i++]);
	}while(ptr[i]);
}

void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str ){
	LCD_goToRowCol(row , col);
	LCD_displayString(str);
}
void LCD_clearScreen(void){
	LCD_sendCommand(0x01); //clear display
}
void LCD_intToString(int data){
	unsigned char buff[16]; /* String to hold the ascii result */
	// itoa(data,buff,10); /* 10 for decimal */
	sprintf(buff, "%s" , data);
	 LCD_displayString(buff);
}

void LCD_init(){
	LCD_DDR_CTRL |=(1<<RS) | (1<<RW) | (1<<E);
	LCD_DDR_DATA = 0XFF;
	LCD_sendCommand(0x38);
	LCD_sendCommand(0x0C);


}




int main(){

	LCD_init();
	//unsigned char pt[30] ="welcome in egypt";
	//LCD_displayString(pt);
	unsigned char key=0;
	while(1){
		key =KEYPAD_pressed();
		LCD_displayCharacter(key);
	}


	return 0;
}






//#include "avr/io.h"
//#include "avr/delay.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//
//#define RS PD0
//#define RW PD1
//#define E  PD2
//#define LCD_CTRL_PORT PORTD
//#define LCD_CTRL_PORT_DIR DDRD
//#define LCD_DATA_PORT PORTC
//#define LCD_DATA_PORT_DIR DDRC
//
//void LCD_init();
//void LCD_command(unsigned char command);
//void LCD_Data(unsigned char data);
//void LCD_displayString(unsigned char *str );
//void LCD_displayCharacter(unsigned char Byte );
//void LCD_goToRowCol(unsigned char row ,unsigned char col );
//void LCD_intToString(int data);
//void LCD_clearScreen(void);
//void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str );
//
//
//
//int main(){
//	LCD_init();
//	LCD_goToRowCol(1,1);
//
//	//unsigned char *a="welcome I'm Ragab";
//	//LCD_displayString(a);
//	LCD_intToString(15);
//
//	while(1)
//	{
//	}
//
//}
//void LCD_init(){
//	LCD_CTRL_PORT_DIR |=(1<<RS) |(1<<RW) |(1<<E);
//	LCD_DATA_PORT_DIR = 0XFF;
//	LCD_command(0x38);
//	LCD_command(0x0C);
//
//
//
//
//}
//void LCD_command(unsigned char command){
//	LCD_CTRL_PORT &=~((1<<RS)|(1<<RW));
//	_delay_ms(1);
//	LCD_CTRL_PORT |=(1<<E);
//	_delay_ms(1);
//	LCD_DATA_PORT = command;
//	_delay_ms(1);
//	LCD_CTRL_PORT &=~(1<<E);
//	_delay_ms(1);
//}
//void LCD_Data(unsigned char data){
//	LCD_CTRL_PORT |=(1<<RS);
//	LCD_CTRL_PORT &=~(1<<RW);
//	_delay_ms(1);
//	LCD_CTRL_PORT |=(1<<E);
//	_delay_ms(1);
//	LCD_DATA_PORT = data;
//	_delay_ms(1);
//	LCD_CTRL_PORT &=~(1<<E);
//	_delay_ms(1);
//}
//void LCD_goToRowCol(unsigned char row ,unsigned char col ){
//	unsigned char fristCharAddr[]={0x80 , 0XC0, 0X94 ,0XD4};
//	LCD_command(fristCharAddr[row-1] + col-1);
//	_delay_ms(1);
//
//}
//void LCD_displayCharacter(unsigned char Byte ){
//	LCD_Data(Byte);
//}
//
//void LCD_displayString(unsigned char *str ){
//	do{
//		LCD_Data(*str++);
//	}while(*str);
//}
//void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str ){
//	LCD_goToRowCol(row , col);
//	LCD_displayString(str);
//}
//void LCD_clearScreen(void){
//	LCD_command(0x01); //clear display
//}
//void LCD_intToString(int data){
//	unsigned char buff[16]; /* String to hold the ascii result */
//	 itoa(data,buff,10); /* 10 for decimal */
//	//sprintf((char *)buff , "%c"  , data);
//	 LCD_displayString(buff);
//}





