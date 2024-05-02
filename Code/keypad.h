/***********************************************************************
*																																			 *					 
*	File Name: keypad.h													 								         *
*																																			 *
* Subject: the keypad header file contains the keypad functions   	   *						 
*					 prototypes.														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include <reg51.h>
#include <delay.h>

/* Important Defines Needded For Keypad */

#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

#define KEYPAD_ROW_PORT										P2
#define KEYPAD_COL_PORT										P2

#define KEYPAD_BUTTON_PRESSED             0
#define KEYPAD_BUTTON_RELEASED            1

/*Define pin and Port for Keypad*/

sbit KEYPAD_ROW_Pin_1 	= KEYPAD_ROW_PORT^7; 
sbit KEYPAD_ROW_Pin_2   = KEYPAD_ROW_PORT^6; 
sbit KEYPAD_ROW_Pin_3   = KEYPAD_ROW_PORT^5; 
sbit KEYPAD_ROW_Pin_4   = KEYPAD_ROW_PORT^4; 

sbit KEYPAD_COL_Pin_1		= KEYPAD_COL_PORT^3; 
sbit KEYPAD_COL_Pin_2   = KEYPAD_COL_PORT^2; 
sbit KEYPAD_COL_Pin_3   = KEYPAD_COL_PORT^1; 
sbit KEYPAD_COL_Pin_4   = KEYPAD_COL_PORT^0; 

/*Keypad Function Prototypes*/
unsigned char  KEYPAD_getPressedKey(void);

#endif