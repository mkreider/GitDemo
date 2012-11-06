/*
 * myLittleProject.c
 *
 * Created: 06.11.2012 11:02:13
 *  Author: mkreider
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

void init(void)
{
	DDRD	= 0xff;
	DDRB	= 0xff;
	DDRC	= 0x00;
	
	PORTB	= 0x00;
	PORTC	= 0x00;
	PORTD	= 0x00;
	adc_init();
	
}

int main(void)
{
    
	init();
	
	uint16_t value;
	
	while(1)
    {
        value = adc_read(0);
		PORTB = (uint8_t)(value & 0x00ff);
		PORTD = (uint8_t)(value>>8);
		_delay_ms(300);
    }
}

