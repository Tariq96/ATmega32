/*
 * ADC.c
 *
 *  Created on: Feb 25, 2020
 *      Author: Tariq A.Diab
 */
#include "ADC.h"
#include <stdio.h>
void void_init_ADC(char prescale,char ref,char channel,char interrupt,char autotrigger,char trigger_source)
{
SET_BIT(ADCSRA,ADEN); // TURN ON ADC
SET_BIT(ADMUX,ADLAR);// LEFT SHIFT DATA REGISTER

	//------------------------------------Setting the prescaler----------------------------------
switch(prescale)
{
case 4:
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	break;
case 8:
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	break;
case 16:
	CLEAR_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	break;
case 32:
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	break;
case 64:
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
	break;
case 128:
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	break;
default :
	CLEAR_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
}

//---------------------------------------------------------selecting refrence-----------------------
switch(ref)
{
case 0:
	CLEAR_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	break;
case 1:
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	break;
case 2:
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	break;
}
//--------------------------------------------------left adjusting --------------------------------------

//--------------------------------------------------------selecting the intital channel -------------------
switch(channel)
{/*
case 0:
	ADMUX=(ADMUX&0XF0)|0;
	break;*/
case 1:
	ADMUX=(ADMUX&0XF0)|1;
	break;
case 2:
	ADMUX=(ADMUX&0XF0)|2;
	break;
case 3:
	ADMUX=(ADMUX&0XF0)|3;
	break;
case 4:
	ADMUX=(ADMUX&0XF0)|4;
	break;
case 5:
	ADMUX=(ADMUX&0XF0)|5;
	break;
case 6:
	ADMUX=(ADMUX&0XF0)|6;
	break;
case 7:
	ADMUX=(ADMUX&0XF0)|7;
	break;

}

//---------------------------------------------------------interrupt------------------------------------------
switch(interrupt)
{
case 0:
	CLEAR_BIT(ADCSRA,ADIE);
	break;
case 1:
	SET_BIT(ADCSRA,ADIE);
	break;
}
//--------------------------------------------------------autotrigger------------------------------------------------
switch(autotrigger)
{
case 0:
	CLEAR_BIT(ADCSRA,ADATE);
	break;
case 1:
	SET_BIT(ADCSRA,ADATE);
	break;
}
//-----------------------------------------------------auto trigger source---------------------------
switch(trigger_source)
{
case 0:
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
	break;

case 1:
	SET_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
	break;
case 2:
	CLEAR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
	break;
case 3:
	SET_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
	break;
case 4:
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
	break;
case 5:
	SET_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
	break;
case 6:
	CLEAR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
	break;
case 7:
	SET_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
	break;


}

}



int int_ADC_read(char channel)
{

	//-----------------------------------------------choosing channel-----------------------------

	switch(channel)
	{
	case 0:
		ADMUX=(ADMUX&0XF0)|0;
		break;
	case 1:
		ADMUX=(ADMUX&0XF0)|1;
		break;
	case 2:
		ADMUX=(ADMUX&0XF0)|2;
		break;
	case 3:
		ADMUX=(ADMUX&0XF0)|3;
		break;
	case 4:
		ADMUX=(ADMUX&0XF0)|4;
		break;
	case 5:
		ADMUX=(ADMUX&0XF0)|5;
		break;
	case 6:
		ADMUX=(ADMUX&0XF0)|6;
		break;
	case 7:
		ADMUX=(ADMUX&0XF0)|7;
		break;
	default :
		break;

	}

SET_BIT(ADCSRA,ADSC);
_delay_us(50);
int adcl=ADCL;

return ((ADCH<<2) | (adcl>>6)) ;

}
