/*
 * uln2003.h
 *
 *  Created on: Mar 19, 2020
 *      Author: Tariq A.Diab
 */

#ifndef HAL_ULN2003_H_
#define HAL_ULN2003_H_

#include "../MCAL/DIO.h"

typedef struct {
	char port ;
	char IN1;
	char IN2;
	char IN3;
	char IN4;
}stepper ;

void void_init_stepper(stepper motor);
void void_steper_step(stepper motor,char n_steps,char dir);

#endif /* HAL_ULN2003_H_ */
