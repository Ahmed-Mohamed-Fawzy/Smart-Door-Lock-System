/***********************************************************************
*																																			 *					 
*	File Name: buzzer.c													 			    			         *
*																																			 *
* Subject: the buzzer source file contains the buzzer functions   	   *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <buzzer.h>

sbit Buzzer = P3^6;

void BUZZER_status(unsigned char status)
{
	if(status == BUZZER_ON)
		{
			Buzzer = BUZZER_ON;
		}
		else if(status == BUZZER_OFF)
		{
			Buzzer = BUZZER_OFF;
		}	
		else
		{
			/*No Action Required*/
		}
}