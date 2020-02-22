/*
 * TIMER.c
 *
 *  Created on: Feb 20, 2020
 *      Author: Tariq A.Diab
 */


#include "TIMER.h"

void void_init_TIMER(char timer ,char state , int prescale , char output)
{
										//SETTING UP THE WAVE GENERATING MODE
switch(state)
{
case 0:

	CLEAR_BIT(timer,WGM00);
	CLEAR_BIT(timer,WGM01);
	break ;
case 1 :
	SET_BIT(timer,WGM00);
	CLEAR_BIT(timer,WGM01);
	break ;
case 2 :
	CLEAR_BIT(timer,WGM00);
	SET_BIT(timer,WGM01);
	break ;
case 3 :
	SET_BIT(timer,WGM00);
	SET_BIT(timer,WGM01);
	break ;
}


									//SETTING UP THE PRESCALLE
switch (prescale)
{
case 1:
	SET_BIT(timer,CS00);
	CLEAR_BIT(timer,CS01);
	CLEAR_BIT(timer,CS02);
	break;
case 8:
	CLEAR_BIT(timer,CS00);
	SET_BIT(timer,CS01);
	CLEAR_BIT(timer,CS02);
	break;
case 64:
	SET_BIT(timer,CS00);
	SET_BIT(timer,CS01);
	CLEAR_BIT(timer,CS02);
	break;
case 256:
	CLEAR_BIT(timer,CS00);
	CLEAR_BIT(timer,CS01);
	SET_BIT(timer,CS02);
	break;
case 1024:
	SET_BIT(timer,CS00);
	CLEAR_BIT(timer,CS01);
	SET_BIT(timer,CS02);
	break;
case 2:
	CLEAR_BIT(timer,CS00);
	SET_BIT(timer,CS01);
	SET_BIT(timer,CS02);
	break;
case 3:
	SET_BIT(timer,CS00);
	SET_BIT(timer,CS01);
	SET_BIT(timer,CS02);
	break;

}


if ((state == normal) || (state==CTC))
{
switch(output)
{
case diconnected:
	CLEAR_BIT(timer,COM00);
	CLEAR_BIT(timer,COM01);
	break;

case toggle:
	SET_BIT(timer,COM00);
	CLEAR_BIT(timer,COM01);
	break;

case none_inverting:
	CLEAR_BIT(timer,COM00);
	SET_BIT(timer,COM01);
	break;

case inverting:
	SET_BIT(timer,COM00);
	SET_BIT(timer,COM01);
	break;


}
}
if ((state == PWM_phase_correct) || (state==fast_PWM))
{
switch(output)
{
case diconnected:
	CLEAR_BIT(timer,COM00);
	CLEAR_BIT(timer,COM01);
	break;

case toggle:                         //give a preprocessing error  an error
	SET_BIT(timer,COM00);
	CLEAR_BIT(timer,COM01);
	break;

case none_inverting:
	CLEAR_BIT(timer,COM00);
	SET_BIT(timer,COM01);
	break;

case inverting:
	SET_BIT(timer,COM00);
	SET_BIT(timer,COM01);
	break;


}

}


}


void void_set_duty(int duty)
{
	duty=duty/100 ;
	duty=duty*256 ;
	OCR0=duty;

}
