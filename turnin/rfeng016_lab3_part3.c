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
    //unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char nib;
    /* Insert your solution below */
    while (1) {
        //tmpA = PINA;
        tmpC = 0x00;
        nib = PINA & 0x0F;
        if (nib >= 1 && nib <= 2) {
            tmpC = 0x20;
	} else if(nib >= 3 && nib <= 4) {
            tmpC = 0x30;
	} else if (nib >= 5 && nib <= 6) {
            tmpC = 0x38;
	} else if (nib >= 7 && nib <= 9) {
            tmpC = 0x3C;
	} else if (nib >= 10 && nib <= 12) {
	    tmpC = 0x3E;
	} else if (nib >= 13 && nib <= 15) {
            tmpC = 0x3F;
	}
        if ((PINA & 0x10) && (PINA & 0x20) && !(PINA & 0x40)) {
            tmpC = tmpC | 0x80;
        }
        if (nib <= 4) {
            tmpC = tmpC | 0x40;
        }
        PORTC = tmpC;
    }
    return 0;
}
