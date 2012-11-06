#include <avr/io.h>

void adc_init(void) {
 
	uint16_t result;

	ADMUX   = (1<<REFS1) | (1<<REFS0);    // interne Referenzspannung nutzen
	ADCSRA  = (1<<ADPS1) | (1<<ADPS0);    // Frequenzvorteiler
	ADCSRA |= (1<<ADEN);                  // ADC aktivieren
						// useless comment

	/* nach Aktivieren des ADC wird ein "Dummy-Readout" empfohlen, man liest
	 also einen Wert und verwirft diesen, um den ADC "warmlaufen zu lassen" */

	ADCSRA |= (1<<ADSC);                  // eine ADC-Wandlung 
	while (ADCSRA & (1<<ADSC) ) {}        // auf Abschluss der Konvertierung warten
	/* ADCW muss einmal gelesen werden, sonst wird Ergebnis der nächsten
	 Wandlung nicht übernommen. */
	result = ADCW;
}
 
/* ADC Einzelmessung */
uint16_t adc_read( uint8_t channel )
{
  
	// ADMUX 3:0 - Kanal waehlen
	// 0000	ADC0	PC0	
	// 0001 ADC1	PC1
	// 0010	ADC2	PC2
	// 0011 ADC3	PC3
	// 0100	ADC4	PC4
	// 0101 ADC5	PC5
	// 0110	ADC6	-- nur in TQFP/MLF
	// 0111 ADC7	-- nur in TQFP/MLF
	// 1000 - 1110 reserved 
	// 1111	GND
 	
	ADMUX = (ADMUX & ~(0x1F)) | (channel & 0x1F);
	ADCSRA |= (1<<ADSC);            // eine Wandlung "single conversion"
	while (ADCSRA & (1<<ADSC) ) {}  // auf Abschluss der Konvertierung warten

// Value: ADCW = Vin * 1024 / Vref  
	return ADCW;                    // ADC auslesen und zurückgeben
}


/* kontinuierliche ADC Messung starten */
void adc_start ( uint8_t channel )
{

}



