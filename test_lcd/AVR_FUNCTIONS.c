
#include "AVR_FUNCTIONS.h"

//#include "util.h"

/*=========================*/
/*       Configure the whole            */
/*       port to be output  	   */
/*            or input                       */
/*=========================*/

 void Port_Direction_All(u8 base,u8 state)
{
    if(state==OUTPUT)
    (*(volatile u8*)(base+1))=0xff;
    else
    (*(volatile u8*)(base+1))=0x00;
}

/*=========================*/
/*       Configure the port              */
/*       direction to a specific 	   */
/*            value		              */
/*=========================*/

 void Port_Direction(u8 base,u8 value)
{
   (*(volatile u8*)(base+1))=value;
}

/*=========================*/
/*       Configure a single pin	   */
/*          in the port to be             */
/*          input or output        	   */
/*=========================*/


 void Pin_Direction(u8 base,u8 pin,u8 state)
{
    if(state==OUTPUT)
    (*(volatile u8*)(base+1))|= (1<<pin);
    else
    (*(volatile u8*)(base+1))&=~(1<<pin);
}

/*=========================*/
/*  	Makes the physical   	   */
/*  	pin electrically                  */
/*  	(grounded) (i.e 0)             */
/*=========================*/

 void Pin_Reset(u8 base,u8 pin)
{
  (*(volatile u8*)(base+2))&=~(1<<pin);
}

/*=========================*/
/*    Makes the physical 		   */
/*    pin 1 electrically  		   */
/*    (connected to Vdd)		   */
/*=========================*/

 void Pin_Set(u8 base,u8 pin)
{
  (*(volatile u8*)(base+2))|= (1<<pin);
}

/*=========================*/
/*    Assign the required  	   */
/*    value to the      		   */
/*    physical port   	              */
/*=========================*/

 void Port_Write(u8 base ,u8 value)
{
   (*(volatile u8*)(base+2))=value;
}

/*=========================*/
/*   Read the port value  	   */
/*=========================*/

 u8 Port_Read(u8 base)
{
    return(*(volatile u8*)base);
}

/*=========================*/
/*    Assign 0 or 1      		   */
/*    (electrically)       		   */
/*    to a specific pin		   */
/*=========================*/

 void Pin_Write(u8 base,u8 pin,u8 value)
{
    if(value==1)
    (*(volatile u8*)(base+2))|= 1<<pin;
    else
    (*(volatile u8*)(base+2))&=~(1<<pin);
}

/*=========================*/
/*    Read pin value   		   */
/*(whole expression is                  */
/* used to evaluate value) 	   */
/*=========================*/

 u8 Pin_Read(u8 base,u8 pin)
{
    if((*(volatile u8*)(base))&&(1<<pin))
        return 1;
    else
        return 0;

}
