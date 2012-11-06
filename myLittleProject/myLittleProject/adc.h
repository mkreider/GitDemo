#ifndef _ADC_H_
#define _ADC_H_

void adc_init(void);
uint16_t adc_read( uint8_t channel );
void adc_start( uint8_t channel_mask );
void adc_stop( uint8_t channel_mask );
void adc_stopall( void );

#endif
