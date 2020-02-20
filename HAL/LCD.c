/*
 * LCD.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Tariq A.Diab
 */

#include "LCD.h"

void void_init_lcd()
{
	//initalizing MCU DIO pins

void_init_pin(MCU_d_PORT,d4,1);
void_init_pin(MCU_d_PORT,d5,1);
void_init_pin(MCU_d_PORT,d6,1);
void_init_pin(MCU_d_PORT,d7,1);

void_init_pin(MCU_rs_PORT,rs,1);
void_init_pin(MCU_e_PORT,e,1);

	// initalizing LCD
void_LCD_init_Command(0x30);
_delay_ms(10);
void_LCD_init_Command(0x30);
_delay_ms(10);
void_LCD_init_Command(0x30);
_delay_ms(10);
void_LCD_init_Command(0x20);
_delay_ms(10);
_delay_ms(10);
void_lcd_send_command(_4bit);                          // intializing the lcd in the bit bus mode
void_lcd_send_command(cursor_off);					      // turning the curser off
void_lcd_send_command(incrimental);					      // setting the lcd in incrimental mode
void_lcd_send_command(set_ddram_80h);				          // adress 80H in the DDRAM
_delay_ms(20);
}
void void_lcd_send_command( char command)
{
	void_write_pin(MCU_rs_PORT,rs,0);                  // LOW on rs  pin to prepare the lcd for a command

	void_write_port(MCU_d_PORT,WRITE_MOST(command));   //writing the 4 most bits in the command byte
	void_pulse();									   //signaling a pulse for the enable pin
	void_write_port(MCU_d_PORT,WRITE_LEST(command));   //writing the 4 least bits in the command byte
	void_pulse();									   //signaling a pulse for the enable pin

}
void void_lcd_send_data( char data)
{


	void_write_pin(MCU_rs_PORT,rs,1);                  // HIGH on rs to prepare the lcd for a character
	void_write_port(MCU_d_PORT,WRITE_MOST(data));      //writing the 4 most bits in the character byte
	void_pulse();									   //signaling a pulse for the enable pin
	void_write_port(MCU_d_PORT,WRITE_LEST(data));      //writing the 4 least bits in the character byte
	void_pulse();


}
void void_lcd_print( char * string)
{
	int i =0;
	while (string[i] != 0)
	{
		void_lcd_send_data(string[i]);
		i++;

	}


}
void void_lcd_clear()
{
	void_lcd_send_command(clear);
}
void void_lcd_goto(char y ,char x)
{
	char lcd_screen_adresses[]={0x80,0xc0};
	/* 0x80 is the first line and corespond to adress 00H in DDRAM
	   0xc0 is the second line and corespond to adress 40H in DDRAM */
	void_lcd_send_command(( lcd_screen_adresses[y-1] + (x-1)) );
	_delay_ms(20);


}

void void_pulse()
{
	void_write_pin(MCU_e_PORT,e,1);
	_delay_ms(1);
	void_write_pin(MCU_e_PORT,e,0);
	_delay_ms(1);
}




void void_LCD_init_Command(unsigned char command)
{
	void_write_pin(MCU_rs_PORT,rs,0);


	void_write_port(MCU_d_PORT,WRITE_MOST(command));
	void_pulse();


}







