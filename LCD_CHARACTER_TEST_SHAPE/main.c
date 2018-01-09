/*
 * main.c
 *
 *  Created on: ٢٤‏/٠٤‏/٢٠١٧
 *      Author: RAGAB
 */


#include "lcdlib.h"


void LCD_build(unsigned char location, unsigned char *ptr){
      unsigned char i;
      if(location<8){
          LCD_command(0x40+(location*8));
          for(i=0;i<8;i++)
             LCD_Data(ptr[ i ]);
     }

}


int main(){
		LCD_init();

//		const char *a="welcome I'm Ragab";
//		LCD_displayString(a);
		storeShape(1,2);

	//	LCD_build(1,shape);
		while(1);

		return 0;

}
