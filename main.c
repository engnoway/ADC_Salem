/*
 * main.c
 *
 *  Created on: Aug 3, 2016
 *      Author: mohamed
 */

#include "types.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include <avr/io.h>
int main(void)
{

	u16 adc_result0=0;
	u16 adcA=0;
	DDRC=255;///output
	DIO_voidInit();
    ADC_init();

	while(1)
	{
		adc_result0 = adc_read(0);//digital val (0:1023)
PORTC=adc_result0;
		  DIO_u8WritePortVal(2,adc_result0);
	  adcA = (adc_result0*5.0*1000)/1024.0;//mv


	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////
//#define F_CPU 8000000UL
/*
#include "types.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

//#define BAUDRATE 9600
//#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

uint16_t adc_value;						//Variable used to store the value read from the ADC
char buffer[5];							//Output of the itoa function

//void adc_init(void);					//Function to initialize/configure the ADC
//uint16_t read_adc(uint8_t channel);		//Function to read an arbitrary analog channel/pin
//void USART_init(void);					//Function to initialize and configure the USART/serial
//void USART_send( unsigned char data);   //Function that sends a char over the serial port
//void USART_putstring(char* StringPtr);   //Function that sends a string over the serial port

int main(void){
//DDRC=255;///output
	DIO_voidInit();
ADC_init();							//Setup the ADC
//	USART_init();						//Setup the USART

	while(1)							//Our infinite loop
	{
	//USART_putstring("welcome");
		adc_value = adc_read(0);
		DIO_u8WritePortVal(2,adc_value);
//PORTC=adc_value ;
		//itoa(adc_value, buffer, 10);
	//	USART_putstring(buffer);
	//	USART_putstring("  ");
	//	_delay_ms(500);
	//	USART_send('\r');
	//	USART_send('\n');                //This two lines are to tell to the terminal to change line
	}
	return 0;
}
/*
void adc_init(void){
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));   // 16Mhz/128 = 125Khz the ADC reference clock
	ADMUX |= (1<<REFS0);							// Voltage reference from Avcc (5v)
	ADCSRA |= (1<<ADEN);							// Turn on ADC
	ADCSRA |= (1<<ADSC);							// Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}*/
/*
uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xF0;									// Clear the older channel that was read
	ADMUX |= channel;								// Defines the new ADC channel to be read
	ADCSRA |= (1<<ADSC);							// Starts a new conversion
	while(ADCSRA & (1<<ADSC));						// Wait until the conversion is done
	return ADCW;									// Returns the ADC value of the chosen channel
}*/
/*
void USART_init(void){

	UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRRL = (uint8_t)(BAUD_PRESCALLER);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
}

void USART_send( unsigned char data){

	while(!(UCSRA & (1<<UDRE)));
	UDR = data;

}

void USART_putstring(char* StringPtr){

	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
	StringPtr++;}

}*/
