


#include "LCD_code.h"


void LCD_Command(u8 command){
	Pin_Reset(cmd,rs);	//Reset RS for command write

	if(mode==8)			// 8-bit mode
	Port_Write(data,command);
	else				// 4-bit mode

	{					// Move the MSB first
		Port_Write(data,assign_hinibble(data,get_hinibble(command)));

		Pin_Set(cmd,e);
		_delay_us(1);
		Pin_Reset(cmd,e); // E from High to Low to latch command
		_delay_us(100);

						  // Move the LSB
		Port_Write(data,assign_hinibble(data,get_lonibble(command)));
	}

	Pin_Set(cmd,e);
	_delay_us(1);
	Pin_Reset(cmd,e);
	_delay_us(100);
}

 void LCD_Out(u8 yourdata){
	Pin_Set(cmd,rs);	// Enable RS for data transfer

	if(mode==8)			// send command on the data pins at once
		Port_Write(data,yourdata);

		else
		{
			Port_Write(data,assign_hinibble(data,get_hinibble(yourdata)));
			Pin_Set(cmd,e);
			_delay_us(1);
			Pin_Reset(cmd,e);
			_delay_us(100);
			Port_Write(data,assign_hinibble(data,get_lonibble(yourdata)));
		}

		Pin_Set(cmd,e);
		_delay_us(1);
		Pin_Reset(cmd,e);
		_delay_us(100);
}


 void LCD_Init()
{
	Port_Direction(data,0xff);
	Port_Direction(cmd,0xff);
	Port_Write(data,0);

	Pin_Reset(cmd,e); // Reset E pin
	_delay_ms(2);	  // wait for 20 ms

	if(mode==8)
	{
		_delay_ms(2);
		LCD_Command(0x38);
	}
	else
	{
		LCD_Command(0x33);                   //init command
		LCD_Command(0x32);                  //init command
		LCD_Command(0x28);                 //init command
	}

	LCD_Command(0x0e);                         //init command
	LCD_Command(0x01);                         //init command
	_delay_ms(2);
	LCD_Command(0x06);                        //init command

}

 void LCD_Print(u8* str)
{
	u8 i;
	for(i=0;str[i]!='\0';++i)
	{
		LCD_Out(str[i]);
	}
}
