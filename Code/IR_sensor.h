/***********************************************************************
*																																			 *					 
*	File Name: IR_sensor.c													 						         *
*																																			 *
* Subject: the IR source file contains the IR functions   	           *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/


#ifndef __IR_SENSOR_H__
#define __IR_SENSOR_H__

#include <reg51.h>

#define IR_DETECT				0
#define IR_SLEEP        1


/*IR Sensor Prototypes*/
unsigned char IR_readStatus(void);



#endif