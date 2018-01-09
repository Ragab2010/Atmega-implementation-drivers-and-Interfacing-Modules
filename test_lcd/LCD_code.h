/*
 * LCD_code.h
 *
 *  Created on: Oct 10, 2017
 *      Author: admin
 */




#ifndef LCD_CODE_H_
#define LCD_CODE_H_


#include "AVR_FUNCTIONS.h"
#include "util/delay.h"
#include "typedefs.h"
#include "LCD_user.h"


 void LCD_Init();
 void LCD_Command(u8 command);
 void LCD_Print(u8* str);


#endif /* LCD_CODE_H_ */
