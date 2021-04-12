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
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    //unsigned char tmpA;
    unsigned char tmpB;
    unsigned char tmpC;
    /* Insert your solution below */
    while (1) {
        tmpB = (PINA & 0xF0) >> 4;
        tmpC = (PINA & 0x0F) << 4;

        PORTB = tmpB;
        PORTC = tmpC;
    }
    return 0;
}
