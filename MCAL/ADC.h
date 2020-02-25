/*
 * ADC.h
 *
 *  Created on: Feb 25, 2020
 *      Author: Tariq A.Diab
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include "../Services_layers/Services_layers.h"
#include <avr/interrupt.h>


void void_init_ADC(char prescale,char ref,char channel,char interrupt,char autotrigger,char trigger_source);
int int_ADC_read(char channel);

#endif /* MCAL_ADC_H_ */
