/***********************************************************************
*																																			 *					 
*	File Name: servo.h													 								         *
*																																			 *
* Subject: the servo header file contains the servo functions proto    *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/


#ifndef __SERVO_H__
#define __SERVO_H__

#define SERVO_ROTATE    0
#define SERVO_STOP      1

/*Servo Motor Functions*/

void Timer0_Start(void);

void SERVO_init(void);

void SERVO_rotateDegree(unsigned char TH1_value, unsigned char TL1_value);







#endif