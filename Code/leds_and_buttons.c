/***********************************************************************
*																																			 *					 
*	File Name: leds_and_buttons.c													 			    		 *
*																																			 *
* Subject: the leds source file contains the leds functions   	       *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <leds_and_buttons.h>

sbit R_led  = P0^4;
sbit Y_led  = P0^5;
sbit G_led  = P0^6;

void RED_ledStatus(unsigned char status)
{
		if(status == LED_ON)
		{
			R_led = LED_ON;
		}
		else if(status == LED_OFF)
		{
			R_led = LED_OFF;
		}	
		else
		{
			/*No Action Required*/
		}
}

void YELLOW_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			Y_led = LED_ON;
		}
		else if(status == LED_OFF)
		{
			Y_led = LED_OFF;
		}	
		else
		{
			/*No Action Required*/
		}
}

void GREEN_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			G_led = LED_ON;
		}
		else if(status == LED_OFF)
		{
			G_led = LED_OFF;
		}	
		else
		{
			/*No Action Required*/
		}
}
