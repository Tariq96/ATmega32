/*
 * Services_layers.h
 *
 *  Created on: Aug 29, 2018
 *      Author: root
 */

#ifndef SERVICES_LAYERS_H_
#define SERVICES_LAYERS_H_


#define SET_BIT(PORTNAME,PIN_NUMBER) (PORTNAME |=(1<<PIN_NUMBER))
#define CLEAR_BIT(PORTNAME,PIN_NUMBER) (PORTNAME &=~(1<<PIN_NUMBER))
#define TOGGLE_BIT(PORTNAME,PIN_NUMBER) (PORTNAME ^=(1<<PIN_NUMBER))
#define READ_BIT(PORTNAME,PIN_NUMBER) (PORTNAME & (1<<PIN_NUMBER))
enum
{
	INPUT,
	OUTPUT
};

enum
{
	LOW,
	HIGH
};


#endif /* SERVICES_LAYERS_H_ */
