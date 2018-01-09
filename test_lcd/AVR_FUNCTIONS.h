
/*=========================*/
/*  Functions definitions  	   */
/*=========================*/

#ifndef LCD_FUNCTION_H_
#define LCD_FUNCTION_H_
#include "typedefs.h"
#include "AVR_INTERFACE.h"
#include "util.h"

void Port_Direction_All(u8 base,u8 state);		// Configure the whole port direction as input or output

void Port_Direction(u8 base,u8 value);        // configure the whole port direction to be a specific value

void Pin_Direction(u8 base,u8 pin,u8 state); // configure a single pin in the port to be output or input

void Pin_Reset(u8 base,u8 pin);             //makes the physical pin 0 electrically (grounded)

void Pin_Set(u8 base,u8 pin);                 //makes the physical pin 1 electrically (connected to vdd)

void Port_Write(u8 base ,u8 value);              //assign the required value to the physical port

u8 Port_Read(u8 base);              // assign the value of the whole port to a value and return it

void Pin_Write(u8 base,u8 pin,u8 value);       // assign 0 or 1 (electrically) to a specific pin

u8 Pin_Read(u8 base,u8 pin);             // note that we use && to get a false or true result from the whole expression

#endif
