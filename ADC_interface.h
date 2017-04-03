/*
 * ADC_interface.h
 *
 *  Created on: Aug 3, 2016
 *      Author: mohamed
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7
////
#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7
///
extern void     ADC_init(void);
extern u16 adc_read(u8 x);
extern void disable_adc(void);



#endif /* ADC_INTERFACE_H_ */
