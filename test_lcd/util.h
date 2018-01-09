#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

//=============
//Port Functions
//=============

#define set_reg(reg) reg=0xFF            	     // set all the bits of the port to 1s

#define toggle(reg) ~(reg)                         // reverse (toggle) all the bits of the port

//=============
//Bit Functions
//=============

												// get the value of a specific bit
#define get_bit(reg,bit_position) ((reg&(1<<bit_position))>>bit_position)

#define set_bit(reg,bit) (reg)|(1<<bit)        // set a specific bit to 1

#define clr_bit(reg,bit) reg&(~(1<<bit))     // clear a specific bit (i.e set to to 0)

#define toggle_bit(reg,bit) reg^=(1<<bit)   // reverse (toggle) a specific bit

                                            	 	  // set a specific bit to specific value
#define assign_bit(reg,bit,value) ((value==1)?(reg|=(1<<bit)):(reg&=~(1<<bit)))

					 // assign a port a hex value
#define assign_port(reg,Hex_Value) reg=(reg|0xFF)&(Hex_Value)

//=============
//Nibble Functions
//=============

#define get_lonibble(reg) reg&(0x0F)       // get the low nibble

#define get_hinibble(reg) (reg&(0xF0))>>4   // get the hi nibble

#define clr_lonibble(reg) reg&(0xF0)       // Clear (reset) low nibble


#define clr_hinibble(reg) (reg&(0x0F))      // Clear (reset) hi nibble


					 // Toggle low nibble
#define toggle_lonibble(reg) (~(reg&(0x0F)))&(reg|(0x0F))


                                            		// Toggle hi nibble
#define toggle_hinibble(reg) (~(reg&(0xF0)))&(reg|(0xF0))


  			                     //assign a specific value to low nibble
#define assign_lonibble(reg,value) (reg&(0xF0))|(value)

				         //assign a specific value to hi nibble
#define assign_hinibble(reg,value) (reg&(0x0F))|(value<<4)

                                           	        //Reverse low and hi nibbles
#define reverse_nibbles(reg) ((get_lownibble(reg))<<4)|(get_hinibble(reg))


#endif // UTIL_H_INCLUDED
