#include "uln2003.h"
#include <util/delay.h>
void void_init_stepper(stepper motor)
{
void_init_pin(motor.port,motor.IN1,1);
void_init_pin(motor.port,motor.IN2,1);
void_init_pin(motor.port,motor.IN3,1);
void_init_pin(motor.port,motor.IN4,1);

void_write_pin(motor.port,motor.IN1,0);
void_write_pin(motor.port,motor.IN2,0);
void_write_pin(motor.port,motor.IN3,0);
void_write_pin(motor.port,motor.IN4,0);
}


void void_steper_step(stepper motor,char n_steps,char dir)
{


char arr[4]={motor.IN1,motor.IN2,motor.IN3,motor.IN4};
switch (dir)
{
case 0:

	for (int step=0; step<=n_steps; step++)
	{
	for (int i =0;i<=4;i++)
	{
		void_write_pin(motor.port,arr[i],1);
		_delay_ms(100);
		void_write_pin(motor.port,arr[i],0);

	}
	}
break;
case 1:
	for (int step=0; step<=n_steps; step++)
	{
	for (int i =4;i>=0;i--)
	{
		void_write_pin(motor.port,arr[i],1);
		_delay_ms(50);
		void_write_pin(motor.port,arr[i],0);

	}
	}
break ;
}
}
