/*
 * KEYPAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#include "KEYPAD.h"

unsigned char KEYPAD_pressed(){
	unsigned char col , row;
	unsigned char keypad_matrix[ROW][COL]=
		   {{'1','2','3'},
			{'4','5','6'},
			{'7','8','9'},
			{'*','0','#'}};
while(1){
	for(col =0 ; col<COL ; col++)
		{
			KEYPAD_DDR =(0b00010000<<col) ;
			KEYPAD_CTRL = 0x00;
			_delay_ms(30);
			for(row=0 ;row <ROW ; row++){
				if(!(KEYPAD_PIN &(1<<row))){
					while(!(KEYPAD_PIN &(1<<row)));//polling to print one key
					return keypad_matrix[row][col];
				}

			}
		}

}



}


