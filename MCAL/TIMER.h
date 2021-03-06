/*
 * TIMER.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Tariq A.Diab
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_

#include "../Services_layers/Services_layers.h"
#include <avr/io.h>
#include <avr/interrupt.h>

//WAVE GENERATION MODE
#define normal   0
#define PWM      1
#define CTC      2
#define	fast_pwm 3

#define Timer0 0
#define Timer1A 'a'
#define Timer1B 'b'
#define Timer2 2

#define timer0 TCCR0
#define timer1 TCCR1A
#define timer1 TCCR1B
#define timer2 TCCR2

#define normal             0
#define PWM_phase_correct  1
#define CTC                2
#define fast_PWM           3



#define diconnected     0
#define toggle          1
#define none_inverting  2
#define inverting       3

void void_init_TIMER(char timerx ,char state , int prescale , char output);


void void_init_timer_interrupt(char timerx ,char CM_or_OV);

void void_set_duty(char timerx,float duty);

void void_init_pwm(char pin , char frequency);



#endif /* MCAL_TIMER_H_ */
















