/***********************************************************************
*																																			 *					 
*	File Name: leds_and_buttons.h													 			    		 *
*																																			 *
* Subject: the leds header file contains the leds functions   	       *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#ifndef __LEDS_AND_BUTTONS_H__
#define __LEDS_AND_BUTTONS_H__

#include <reg51.h>
#define LED_ON          0
#define LED_OFF         1

void RED_ledStatus(unsigned char status);

void YELLOW_ledStatus(unsigned char status); 

void GREEN_ledStatus(unsigned char status);






#endif