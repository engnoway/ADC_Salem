/*
 * ADC_prog.c
 *
 *  Created on: Aug 3, 2016
 *      Author: mohamed
 */



#include "Types.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include "delay_config.h"
#include "delay.h"
#include "util.h"


void ADC_init(void)
{
	 ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));   // 16Mhz/128 = 125Khz the ADC reference clock
	 ADMUX |= (1<<REFS0); // Voltage reference from Avcc (5v)
	 ADCSRA |= (1<<ADEN); // Turn on ADC
	 ADCSRA |= (1<<ADSC); // Do an initial conversion because this one is the slowest and to ensure that everything is up and running

/*ADMUX=0x40;
ADCSRA=0x85;*/
}


u16 adc_read(u8 ch)
{

	ADMUX &= 0xF0; // Clear the older channel that was read
	 ADMUX |= ch; // Defines the new ADC channel to be read
	 ADCSRA |= (1<<ADSC); // Starts a new conversion
	 while(ADCSRA & (1<<ADSC)); // Wait until the conversion is done
	 return ADC; // Returns the ADC value of the chosen channel
 /* ch &= 0b00000111;
  ADMUX = (ADMUX & 0xE0)|ch;
  Delay_ms(10);

  ADCSRA |= (1<<ADSC);


  while(ADCSRA & (1<<ADSC));

  return (ADC);*/
}

void disable_adc()
{
	ADCSRA = 0x00;
}
