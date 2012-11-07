/*
 * myLittleProject.c
 *
 * Created: 06.11.2012 11:02:13
 *  Author: mkreider
 */ 

// Tim was here


#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

void init(void)
{
	//use ports B and D to show what the ADC read
	DDRD	= 0xff;
	DDRB	= 0xff;
	DDRC	= (1<<PC6); // only C6 is output
	
	PORTB	= 0x00;
	PORTC	= 0x00;	//no pullup for PORTC
	PORTD	= 0x00;

	//initialise ADC
	adc_init();
	
}

int main(void)
{
    uint16_t value;
	
	init();
	
	while(1)
    {
        //read ADC every half second
		
		value = adc_read(0);
		PORTB = (uint8_t)(value & 0x00ff);
		PORTD = (uint8_t)(value>>8);
		_delay_ms(500);
		PORTC ^= (1<<PC6);  // toggle PC6
    }
}

