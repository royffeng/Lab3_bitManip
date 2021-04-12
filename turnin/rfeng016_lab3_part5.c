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
    //DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRD = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
    DDRB = 0xFE; PORTB = 0x01; // Configure port B's 8 pins as outputs
    //unsigned char tmpA;
    unsigned char tmpB;
    unsigned short weight;
    /* Insert your solution below */
    while (1) {
        tmpB = 0x00;
        weight = 0x00;
        
        weight = (PIND << 1);
        weight += PINB & 0x01;
        
        if (weight >= 70) {
            tmpB = tmpB | 0x02;
        } else if (weight > 5) {
            tmpB = tmpB | 0x04;
        } else {} // does nothing
        PORTB = tmpB;
    }
    return 0;
}
