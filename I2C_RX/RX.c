/*
 * RX.c
 *
 *  Created on: ??�/??�/????
 *      Author: RAGAB
 */

#include "avr/io.h"

/*slave mode*/
void I2C_init(){
	//Frequncy eqaul 125KHz
	TWBR = 0X47;
	TWSR = 0X00;
	//TWPS1 TWPS0 = 00   -- no Prescaler

	TWCR = (1<<TWEN);  //Enable the TWI module

}
void I2C_initSlave(unsigned char slaveAddr){
	TWCR = (1<<TWEN);  //Enable the TWI module FRIST IN SLAVE MODE
	TWAR = slaveAddr;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);//ENABLE , CLAER FLAG , SEND ACK
	//WE CAN REMOVE ACK

}
void I2C_listen(){

	while(!(TWCR & (1<<TWINT))); //IS LISIN TO CALL FROM MASTER TO ACK
}


void I2C_start(){
	TWCR = (1<<TWEN) | (1<<TWINT)| (1<<TWSTA);
	//Enable the TWI module
	// make flag be zero
	//Transmit START bit on SDA bus

	while(!(TWCR & (1<<TWINT))); //(start bit is send successfully)
}
void I2C_stop(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO);
	//Enable the TWI module
	// make flag be zero
	//Transmit START bit on SDA bus


}

void I2C_write(unsigned char byte){
	TWDR = byte; // assign byte to DATA REGISTER
	TWCR = (1<<TWINT)|(1<<TWEN);
	// make flag be zero
	//Enable the TWI module

	while(!(TWCR & (1<<TWINT)));//(data is send successfully)
}

unsigned char I2C_read(unsigned char isLast){

	if(isLast == 0){//for more one byte
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		// make flag be zero
		//Enable the TWI module
		//Transmit ACK bit on SDA bus

	}else{//for one byte
		TWCR = (1<<TWINT)|(1<<TWEN);
		// make flag be zero
		//Enable the TWI module
	}


	while(!(TWCR & (1<<TWINT))); //(data received successfully)

	return TWDR ; // return byte from the DATA REGISTER
}

//int main(){
///*this slave receive byte and show it in PORTA*/
//	DDRA =0XFF;
//	PORTA=0X00;
//	I2C_initSlave(0b11000000);
//	I2C_listen();
//	PORTA = I2C_read(1);
//
//	while(1);
//
//	return 0;
//}
//


int main(){
/*this slave send 0x0f to master*/
	I2C_initSlave(0b11000000);
	I2C_listen();
	I2C_write(0x0F);
	while(1);

	return 0;
}



