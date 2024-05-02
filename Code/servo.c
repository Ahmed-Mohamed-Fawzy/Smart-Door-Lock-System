/***********************************************************************
*																																			 *					 
*	File Name: servo.c													 								         *
*																																			 *
* Subject: the servo source file contains the servo functions   	     *						 														  									 *
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <servo.h>
#include <reg51.h>

sbit servo  = P3^4;
unsigned char gTH0_value = 0XF9 ; 
unsigned char gTL0_value  = 0X34; 

/*Servo Motor Functions*/
	
	/*
	Value should be passed to timer 0 to rotate servo:	
		1- For Rotate 0    -> we need  1.5   ms = 0XFA24
		2- For Rotate 90   -> we need  1.74  ms = 0XF934
		3- For Rotate 180  -> we need  2     ms = 0XF830
		4- For Rotate -90  -> we need  1.24  ms = 0XFB28
		5- For Rotate -180 -> we need  0.98  ms = 0XFC2C
	*/

void Timer0_Start(void)
{
	EA   = 1;
	TR0  = 1;
}

void SERVO_init(void)
{
	TMOD = 0X01;
	TH0  = gTH0_value;
	TL0  = gTL0_value;
	ET0  = 1;
}

void SERVO_rotateDegree(unsigned char TH0_value, unsigned char TL0_value)
{
	gTH0_value = TH0_value;
	gTL0_value = TL0_value;
}	

void SERVO_ISR (void) interrupt 1 //timer value 
{
		servo = ~servo;
		TF0   = 0;
		TH0  = gTH0_value;
		TL0  = gTL0_value;
}