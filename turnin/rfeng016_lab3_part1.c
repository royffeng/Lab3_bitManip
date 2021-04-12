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
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmp = 0x00;
    /* Insert your solution below */
    while (1) {
        tmpA = PINA;
        tmpB = PINB;
        tmpC = 0x00;
        while (tmpA != 0x00) {
            tmp = tmpA & 0x01;
            if (tmp != 0x00) {
                tmpC += 1;
            }
            tmpA = tmpA >> 1;
        }
        while (tmpB != 0x00) {
            tmp = tmpB & 0x01;
            if (tmp != 0x00) {
                tmpC += 1;
            } 
            tmpB = tmpB >> 1;
        }
    PORTC = tmpC;
    }
    return 0;
}
