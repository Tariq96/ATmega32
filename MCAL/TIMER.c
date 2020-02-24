/*
 * TIMER.c
 *
 *  Created on: Feb 20, 2020
 *      Author: Tariq A.Diab
 */


#include "TIMER.h"

void void_init_TIMER(char timerx ,char state , int prescale , char output)
{

switch(timerx)
{
case 0:
	//SETTING UP THE WAVE GENERATING MODE
switch(state)
{
case 0:

	CLEAR_BIT(timer0,WGM21);
	CLEAR_BIT(timer0,CS20);
	break ;
case 1 :
	SET_BIT(timer0,WGM00);
	CLEAR_BIT(timer0,WGM01);
	break ;
case 2 :
	CLEAR_BIT(timer0,WGM00);
	SET_BIT(timer0,WGM01);
	break ;
case 3 :
	SET_BIT(timer0,WGM00);
	SET_BIT(timer0,WGM01);
	break ;
}


									//SETTING UP THE PRESCALLE
switch (prescale)
{
case 1:
	SET_BIT(timer0,CS00);
	CLEAR_BIT(timer0,CS01);
	CLEAR_BIT(timer0,CS02);
	break;
case 8:
	CLEAR_BIT(timer0,CS00);
	SET_BIT(timer0,CS01);
	CLEAR_BIT(timer0,CS02);
	break;
case 64:
	SET_BIT(timer0,CS00);
	SET_BIT(timer0,CS01);
	CLEAR_BIT(timer0,CS02);
	break;
case 256:
	CLEAR_BIT(timer0,CS00);
	CLEAR_BIT(timer0,CS01);
	SET_BIT(timer0,CS02);
	break;
case 1024:
	SET_BIT(timer0,CS00);
	CLEAR_BIT(timer0,CS01);
	SET_BIT(timer0,CS02);
	break;
case 2:
	CLEAR_BIT(timer0,CS00);
	SET_BIT(timer0,CS01);
	SET_BIT(timer0,CS02);
	break;
case 3:
	SET_BIT(timer0,CS00);
	SET_BIT(timer0,CS01);
	SET_BIT(timer0,CS02);
	break;

}


if ((state == normal) || (state==CTC))
{
switch(output)
{
case diconnected:
	CLEAR_BIT(timer0,COM00);
	CLEAR_BIT(timer0,COM01);
	break;

case toggle:
	SET_BIT(timer0,COM00);
	CLEAR_BIT(timer0,COM01);
	break;

case none_inverting:
	CLEAR_BIT(timer0,COM00);
	SET_BIT(timer0,COM01);
	break;

case inverting:
	SET_BIT(timer0,COM00);
	SET_BIT(timer0,COM01);
	break;


}
}
if ((state == PWM_phase_correct) || (state==fast_PWM))
{
switch(output)
{
case diconnected:
	CLEAR_BIT(timer0,COM00);
	CLEAR_BIT(timer0,COM01);
	break;

case toggle:                         //give a preprocessing error  an error
	SET_BIT(timer0,COM00);
	CLEAR_BIT(timer0,COM01);
	break;

case none_inverting:
	CLEAR_BIT(timer0,COM00);
	SET_BIT(timer0,COM01);
	break;

case inverting:
	SET_BIT(timer0,COM00);
	SET_BIT(timer0,COM01);
	break;


}

}
break;
//-------------------------------------------------TIMER2----------------------------------------------------------------
case 2:
//SETTING UP THE WAVE GENERATING MODE
switch(state)
{
case 0:

CLEAR_BIT(timer2,WGM20);
CLEAR_BIT(timer2,WGM01);
break ;
case 1 :
SET_BIT(timer2,WGM20);
CLEAR_BIT(timer2,WGM21);
break ;
case 2 :
CLEAR_BIT(timer2,WGM20);
SET_BIT(timer2,WGM21);
break ;
case 3 :
SET_BIT(timer2,WGM20);
SET_BIT(timer2,WGM21);
break ;
}


								//SETTING UP THE PRESCALLE
switch (prescale)
{
case 1:
SET_BIT(timer2,CS00);
CLEAR_BIT(timer2,CS21);
CLEAR_BIT(timer2,CS22);
break;
case 8:
CLEAR_BIT(timer2,CS20);
SET_BIT(timer2,CS21);
CLEAR_BIT(timer2,CS22);
break;
case 64:
SET_BIT(timer2,CS20);
SET_BIT(timer2,CS21);
CLEAR_BIT(timer2,CS22);
break;
case 256:
CLEAR_BIT(timer2,CS20);
CLEAR_BIT(timer2,CS21);
SET_BIT(timer2,CS22);
break;
case 1024:
SET_BIT(timer2,CS20);
CLEAR_BIT(timer2,CS21);
SET_BIT(timer2,CS22);
break;
case 2:
CLEAR_BIT(timer2,CS20);
SET_BIT(timer2,CS21);
SET_BIT(timer2,CS22);
break;
case 3:
SET_BIT(timer2,CS20);
SET_BIT(timer2,CS21);
SET_BIT(timer2,CS22);
break;

}


if ((state == normal) || (state==CTC))
{
switch(output)
{
case diconnected:
CLEAR_BIT(timer2,COM20);
CLEAR_BIT(timer2,COM21);
break;

case toggle:
SET_BIT(timer2,COM20);
CLEAR_BIT(timer2,COM21);
break;

case none_inverting:
CLEAR_BIT(timer2,COM20);
SET_BIT(timer2,COM21);
break;

case inverting:
SET_BIT(timer2,COM20);
SET_BIT(timer2,COM21);
break;


}
}
if ((state == PWM_phase_correct) || (state==fast_PWM))
{
switch(output)
{
case diconnected:
CLEAR_BIT(timer2,COM20);
CLEAR_BIT(timer2,COM21);
break;

case toggle:                         //give a preprocessing error  an error
SET_BIT(timer2,COM20);
CLEAR_BIT(timer2,COM21);
break;

case none_inverting:
CLEAR_BIT(timer2,COM20);
SET_BIT(timer2,COM21);
break;

case inverting:
SET_BIT(timer2,COM20);
SET_BIT(timer2,COM21);
break;


}

}
break;
}

}










void void_set_duty(char timerx,float duty)
{int x;
	switch (timerx){
	case 0:
		duty=duty/100 ;
		duty=duty*256 ;
		 x =duty;
		OCR0=x;
		break;
	case 2:
		duty=duty/100 ;
		duty=duty*256 ;
		 x =duty;
		OCR2=x;
		break;
	}

}



void void_init_timer_interrupt(char timerx , char CM_or_OV)
{
	if (timerx==0)
	{
		if( CM_or_OV==0)
		{
		SET_BIT(TIMSK,OCIE0);
		}
		if( CM_or_OV==1)
		{
		SET_BIT(TIMSK,TOIE0);
		}
	}

	if (timerx==2)
	{
		if( CM_or_OV==0)
		{
		SET_BIT(TIMSK,OCIE2);
		}
		if( CM_or_OV==1)
		{
		SET_BIT(TIMSK,TOIE2);
		}
	}
}
