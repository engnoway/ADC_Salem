/*
 * ADC_private.h
 *
 *  Created on: Aug 3, 2016
 *      Author: mohamed
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define Conc(x0,x1,x2,x3,x4,x5,x6,x7) Conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define Conchelper(z0,z1,z2,z3,z4,z5,z6,z7) 0b##z7##z6##z5##z4##z3##z2##z1##z0

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

///////////
#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7
//////////high byte
#define ADCH0	     0	// ADC Data Register High Byte Bit 0
#define	ADCH1	     1	// ADC Data Register High Byte Bit 1
#define	ADCH2	     2	// ADC Data Register High Byte Bit 2
#define	ADCH3	     3	// ADC Data Register High Byte Bit 3
#define	ADCH4	     4	// ADC Data Register High Byte Bit 4
#define	ADCH5	     5	// ADC Data Register High Byte Bit 5
#define	ADCH6	     6	// ADC Data Register High Byte Bit 6
#define	ADCH7	     7	// ADC Data Register High Byte Bit 7
////////////low byte
#define ADCL0	     0	// ADC Data Register low Byte Bit 0
#define	ADCL1	     1	// ADC Data Register low Byte Bit 1
#define	ADCL2	     2	// ADC Data Register low Byte Bit 2
#define	ADCL3	     3	// ADC Data Register low Byte Bit 3
#define	ADCL4	     4	// ADC Data Register low Byte Bit 4
#define	ADCL5	     5	// ADC Data Register low Byte Bit 5
#define	ADCL6	     6	// ADC Data Register low Byte Bit 6
#define	ADCL7	     7	// ADC Data Register low Byte Bit 7
/////////

#define ADMUX      *((volatile u8*)(0x27))
#define ADCH       *((volatile u8*)(0x25))
#define ADCL       *((volatile u8*)(0x24))
#define ADCSRA     *((volatile u8*)(0x26))
#define ACSR       *((volatile u8*)(0x28))

#define ADC       *((volatile u16*)(0x24))

#endif /* ADC_PRIVATE_H_ */
