#include "../MCAL/DIO.h"
#include <util/delay.h>
#include "../HAL/keypad.h"
#include "../HAL/LCD.h"
#include "../MCAL/TIMER.h"
#include <stdio.h>
#include "../Services_layers/Services_layers.h"
#include <avr/interrupt.h>
#include "../HAL/uln2003.h"



char lcd[50] ;

void void_lcd_update(char * string);
void void_time_input(char * arr,char input);
void void_update_status();
char time[4]={0,0,0,0};
stepper stepper1 ;
char keypad_map[4][3]={{{1},{2},{3}},{{4},{5},{6}},{{7},{8},{9}},{{'a'},{0},{'h'}}};
key k ;
int mins , secs , time_s;
int x;
int main()
{
	void_init_pin('c',2,1);
	void_init_pin('c',3,1);
	void_init_pin('d',5,1);
	void_init_pin('d',4,1);


	void_init_pin('a',0,0);


	stepper1.port='b';
	stepper1.IN1 = 4;
	stepper1.IN2=5;
	stepper1.IN3=6;
	stepper1.IN4=7;
	void_init_keypad();
	void_init_stepper(stepper1);


	void_init_lcd();
	void_lcd_clear();

	void_lcd_print(lcd);
	void_lcd_update("sterilizer");

	while (1)
	{


        k=key_read_keypad();
        if (k.x !=5)
        {
            void_time_input(time,keypad_map[k.x][k.y]);
            sprintf(lcd,"%d%d:%d%d",time[0],time[1],time[2],time[3]);
            void_update_status();
            _delay_ms(200);
        }

        x=char_read_pin('a',0);
        if (x==0)
        {
        	if (time_s==0 )
        	{
        		time_s=60;
        	}
        	int steps=5*time_s;
        	void_write_pin('c',2,1);
        	void_write_pin('d',5,0);
        	void_steper_step(stepper1,steps,0);
    		void_write_pin('c',2,0);
    		void_write_pin('d',5,0);
    		time_s=0;

        }

		//void_steper_step(stepper1,50,0);

		//void_write_pin('c',2,1);
		//void_write_pin('d',5,0);



		//void_write_pin('c',2,0);
		//void_write_pin('d',5,0);

	}


}


void void_lcd_update(char * string)
{
	sprintf(lcd,string);
	void_lcd_clear();
	void_lcd_print(lcd);
	_delay_ms(100);


}

void void_time_input(char * arr,char input)
{
    if (arr[0]==0)
    {
        arr[0]=arr[1];
        arr[1]=arr[2];
        arr[2]=arr[3];
        arr[3]=input;


    }
    mins = arr[0]*10+arr[1]  ;
    secs = arr[2]*10+arr[3]  ;
    time_s =mins*60+secs  ;
}

void void_update_status()
{

        void_lcd_clear();
        void_lcd_print(lcd);
        _delay_ms(100);

}
void void_operation
