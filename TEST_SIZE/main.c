/*
 * main.c
 *
 *  Created on: ٣١‏/٠٣‏/٢٠١٧
 *      Author: RAGAB
 */

#include "avr/io.h"

unsigned int nn;

int main() {

	DDRB = 0XFF;
	unsigned int n;
	unsigned int a=256;
	unsigned int b=257;
	unsigned int c=a + b;
	unsigned char ss=nn*255;
	PORTB = c;

	while(1){

	}
	return 0;
}

