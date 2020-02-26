/*
 * TEMP.c
 *
 *  Created on: Sep 15, 2018
 *      Author: Tariq A.Diab
 */
#include "../HAL/TEMP.h"
#include "../MCAL/ADC.h"


float TEMP_READ()
{
	void_init_ADC(64,1,5,0,0,0);

	float temp=int_ADC_read(5);
	return (temp*4.88)/10;




}
