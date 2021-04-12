/*	Author: rfeng016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
        //tmpA = PINA;
        tmpC = 0x00;
        if (PINA >= 1 && PINA <= 2) {
			tempC = 0x20;
		} else if(PINA >= 3 && PINA <= 4) {
			tempC = 0x30;
		} else if (PINA >= 5 && PINA <= 6) {
			tempC = 0x38;
		} else if (PINA >= 7 && PINA <= 9) {
			tempC = 0x3C;
		} else if (PINA >= 10 && PINA <= 12) {
			tempC = 0x3E;
		} else if (PINA >= 13 && PINA <= 15) {
            tempC = 0x3F;
		}
		if (PINA >= 4) {
            tempC = tempC | 0x40;
		}
        PORTC = tmpC;
    }
    return 0;
}
