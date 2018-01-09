/*
 * KEYPAD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: RAGAB
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "avr/io.h"
#include "util/delay.h"

#define KEYPAD_DDR DDRB
#define KEYPAD_CTRL PORTB
#define KEYPAD_PIN  PINB
#define COL 3
#define ROW 4
typedef unsigned char uint8;


unsigned char KEYPAD_pressed();

#endif /* KEYPAD_H_ */
