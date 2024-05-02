/***********************************************************************
*																																			 *					 
*	File Name: lcd.c														 								         *
*																																			 *
* Subject: the lcd source file contains the lcd functions    	    		 *						 
*																																			 *	 
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <lcd.h>

/*Define pin Rs and En for LCD*/

sbit LCD_RS = LCD_RS_PORT_ID^LCD_RS_PIN_ID; 
sbit LCD_En = LCD_E_PORT_ID^LCD_E_PIN_ID; 
	
void LCD_init(void)
{
	/*Configure the Direction of Rs Pin to output pin*/
	LCD_RS = 0;
	/*Configure the Direction of En Pin to output pin*/
	LCD_En = 0;
	/*This Delay 20m sec needed from datasheet*/
	delayms(20);
	/*Set the LCD_DATA_PORT_ID to output port */
	LCD_DATA_PORT_ID = 0x00;
	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	/* cursor off */
	LCD_sendCommand(LCD_CURSOR_OFF); 
	/* clear LCD at the beginning */
	LCD_sendCommand(LCD_CLEAR_COMMAND); 
}

void LCD_sendCommand(unsigned char command)
{
	/*
		To send command on LCD you should put:
		1- Rs to 0 
		2- En to 1
		you should make a delay 1m sec as written datasheet
	*/
	LCD_RS = 0;
	delayms(1);
	LCD_En = 1;
	delayms(1);
	/*
		To send command on LCD you should put:
		1- the command you need on Lcd Data Port  
		2- En to 0
		you should make a delay 1m sec as written datasheet
	*/
	LCD_DATA_PORT_ID = command;
	delayms(1);
	LCD_En = 0;
	delayms(1);
}

void LCD_displayCharacter(unsigned char my_data)
{
/*
		To send command on LCD you should put:
		1- Rs to 1 
		2- En to 1
		you should make a delay 1m sec as written datasheet
	*/
	LCD_RS = 1;
	delayms(1);
	LCD_En = 1;
	delayms(1);
	
	/*
		To send data_ on LCD you should put:
		1- the command you need on Lcd Data Port  
		2- En to 0
		you should make a delay 1m sec as written datasheet
	*/	
	LCD_DATA_PORT_ID = my_data;
	delayms(1);
	LCD_En = 0;
	delayms(1);
}

void LCD_displayString(const char *Str)
{
	unsigned char i;
	for(i=0; Str[i] != '\0';i++)
		{
			LCD_displayCharacter(Str[i]);
		}
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); 
}

void LCD_moveCursor(unsigned char row,unsigned char col)
{
		unsigned char  memory_address;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			memory_address=col;
				break;
		case 1:
			memory_address=col+0x40;
				break;
		case 2:
			memory_address=col+0x10;
				break;
		case 3:
			memory_address=col+0x50;
				break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(memory_address | LCD_SET_CURSOR_LOCATION);
}
