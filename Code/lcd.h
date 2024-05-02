/***********************************************************************
*																																			 *					 
*	File Name: lcd.h														 								         *
*																																			 *
* Subject: the lcd header file contains the lcd functions prototypes   *						 
*																																			 *	 
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#ifndef __LCD_H__
#define __LCD_H__

#include <reg51.h>
#include <delay.h>

/* Important Defines Needded For LCD */

#define LCD_RS_PORT_ID                 P0
#define LCD_RS_PIN_ID                  0

#define LCD_E_PORT_ID                  P0
#define LCD_E_PIN_ID                   1

#define LCD_DATA_PORT_ID               P1

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/* LCD Functions prototypes */

void LCD_init(void);

void LCD_sendCommand(unsigned char command);

void LCD_displayCharacter(unsigned char my_data);

void LCD_displayString(const char *Str);

void LCD_clearScreen(void);

void LCD_moveCursor(unsigned char row,unsigned char col);




#endif