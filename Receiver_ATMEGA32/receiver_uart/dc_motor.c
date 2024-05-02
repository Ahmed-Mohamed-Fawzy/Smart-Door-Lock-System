/*
 * dc_motor.c
 *
 *  Created on: Apr 22, 2024
 *      Author: shirbiny
 */

#include "dc_motor.h"
#include "std_types.h"
#include "gpio.h"

void Dc_Motor_Init(void)
{
	GPIO_setupPinDirection(PORTC_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN2_ID,PIN_OUTPUT);
	GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,PIN2_ID,LOGIC_LOW);
}

void Dc_Motor_Rotate(uint8 direction)
{
	GPIO_writePin(PORTC_ID,PIN2_ID,LOGIC_HIGH);

	switch(direction)
	{

	case ROTATE_LEFT:
		GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_LOW);
		break;

	case ROTATE_RIGHT:
		GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_LOW);
		break;
	case ROTATE_STOP:
		GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_LOW);
		GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_LOW);
		break;

	default:
		GPIO_writePin(PORTC_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTC_ID,PIN1_ID,LOGIC_LOW);
		break;
	}
}
