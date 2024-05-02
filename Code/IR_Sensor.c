/***********************************************************************
*																																			 *					 
*	File Name: IR_sensor.h													 						         *
*																																			 *
* Subject: the IR header file contains the IR functions prototypes     *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <IR_sensor.h>

sbit IR_pin = P3^3;

unsigned char IR_readStatus(void)
{
	/*Local Variable Store the Value that IR read*/
	unsigned char IR_status;
	/* Define IR pin as Input Pin*/
	IR_pin = 1;
	
	if(IR_pin == IR_DETECT)
		{
			IR_status = 0;
		}
		else if(IR_pin == IR_SLEEP)
		{
			IR_status = 1;
		}	
		else
		{
			/*No Action Required*/
		}
		
		return IR_status ;
}