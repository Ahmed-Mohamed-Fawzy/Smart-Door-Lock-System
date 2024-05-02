/***********************************************************************
 *																	   *
 *	File Name: App.c												   *
 *																	   *
 * Subject: the application source file contains the flow of code  	   *
 *																	   *
 *	Date: 15-4-2024													   *
 *																	   *
 * Created By: Group 1 -> Embedded System Course						   *
 *																	   *
 ***********************************************************************/

#include "uart.h"
#include "gpio.h"
#include "util/delay.h"
#include "lcd.h"
#include "dc_motor.h"

void Lcd_SmartFeaurtres(void)
{
	LCD_moveCursor(0,0);
	LCD_displayString("AC Status:   ");
	LCD_moveCursor(1,0);
	LCD_displayString("Light Status:   ");
}
void Lcd_HomeScreen(void)
{
	LCD_clearScreen();
	LCD_displayString("   Smart Home   ");
	LCD_moveCursor(1,0);
	LCD_displayString(" We Always Here ");
}
int main(void)
{
	uint8 received_byte = 0;
	uint8 AC_button_count=0;
	uint8 Light_button_count=0;

	UART_init(9600);
	LCD_init();
	Dc_Motor_Init();

	/*Set the direction of Motor Pins*/
	GPIO_setupPinDirection(PORTC_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,PIN2_ID,PIN_OUTPUT);

	/*Set the direction of AC Button Pin as input*/
	GPIO_setupPinDirection(PORTD_ID,PIN2_ID,PIN_INPUT);
	GPIO_writePin(PORTD_ID,PIN2_ID,LOGIC_HIGH);

	/*Set the direction of Light Button Pin as input*/
	GPIO_setupPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT);
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_HIGH);

	/*Set the direction of Light leds Pin as input*/
	GPIO_setupPortDirection(PORTB_ID,PORT_OUTPUT);
	GPIO_writePort(PORTB_ID,0XFF);

	Lcd_HomeScreen();

	while(1)
	{
		/*This variable always receive from the 8051*/
		received_byte = UART_recieveByte();

		/* if receiver from 8051 char 'S' Means start */
		while(received_byte =='S')
		{
			Lcd_SmartFeaurtres();

			if(GPIO_readPin(PORTD_ID,PIN2_ID) == LOGIC_LOW)
			{
				_delay_ms(30);

				if(GPIO_readPin(PORTD_ID,PIN2_ID) == LOGIC_LOW)
				{
					AC_button_count++;
					if(AC_button_count == 1)
					{
						LCD_moveCursor(0,10);
						LCD_displayString("ON");
						Dc_Motor_Rotate(ROTATE_RIGHT);
						_delay_ms(1000);
					}
					else if(AC_button_count == 2)
					{
						AC_button_count = 0;
						LCD_moveCursor(0,10);
						LCD_displayString("OFF");
						Dc_Motor_Rotate(ROTATE_STOP);
						_delay_ms(1000);
					}
					else
					{
						/* Do No Thing*/
					}

					while(GPIO_readPin(PORTD_ID,PIN2_ID) == LOGIC_LOW);
				}
				else
				{
					//Do no thing
				}
			}

			if(GPIO_readPin(PORTD_ID,PIN3_ID) == LOGIC_LOW)
			{
				_delay_ms(30);

				if(GPIO_readPin(PORTD_ID,PIN3_ID) == LOGIC_LOW)
				{
					Light_button_count++;
					if(Light_button_count == 1)
					{
						LCD_moveCursor(1,14);
						LCD_displayString("M1");
						GPIO_writePort(PORTB_ID,0XFC);
						_delay_ms(500);
					}
					else if(Light_button_count == 2)
					{
						LCD_moveCursor(1,14);
						LCD_displayString("M2");
						GPIO_writePort(PORTB_ID,0XF3);
						_delay_ms(500);
					}
					else if(Light_button_count == 3)
					{
						LCD_moveCursor(1,14);
						LCD_displayString("M3");
						GPIO_writePort(PORTB_ID,0XCF);
						_delay_ms(500);
					}
					else if(Light_button_count == 4)
					{

						LCD_moveCursor(1,14);
						LCD_displayString("M4");
						GPIO_writePort(PORTB_ID,0X3F);
						_delay_ms(500);
					}
					else if(Light_button_count == 5)
					{
						Light_button_count = 0;
						LCD_moveCursor(1,13);
						LCD_displayString("OFF");
						GPIO_writePort(PORTB_ID,0XFF);
						_delay_ms(500);
					}
					else
					{
						/* Do No Thing*/
					}

					while(GPIO_readPin(PORTD_ID,PIN3_ID) == 0);
				}
			}

		}

		Lcd_HomeScreen();

	}
}
