/***********************************************************************
*																																			 *					 
*	File Name: App.c														 								         *
*																																			 *
* Subject: the application source file contains the flow of code  		 *						 
*																																			 *	 
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <reg51.h>
#include <lcd.h>
#include <keypad.h>
#include <servo.h>
#include <uart.h>
#include <IR_sensor.h>
#include <buzzer.h>
#include <leds_and_buttons.h>
#include <delay.h>

/****************************************************
*								  Global Variables	 		  					*
****************************************************/

/* The pointer to char_ act as array of char_ (string) for the saved pass */
const unsigned char  saved_pass[5] = {'1','2','2','1','\0'};
/* The array that store the current password the user enterd */
unsigned char entered_pass[5];
/* The flag used for check if the flag is true or not */
unsigned char correct_pass_flag = 0;
/* This flag needed for checking if the re-enterd password correct or not */
unsigned char reEnter_pass_flag = 0;
/* This counter indicats to limitation of password entering times */
unsigned char num_ofCorrect_Password = 3;

/****************************************************
*							 Functions Prototypes									*
****************************************************/
/***********************************************************************
*																																			 *
*	Function Name: receive_PasswordfromUser															 *
*																																			 *
* Behaviour: the function used for getting the password from the user  *
*						 and store it in the entered_pass array.									 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: void																								 *
*																																			 *
***********************************************************************/
void receive_PasswordfromUser(void);

/***********************************************************************
*																																			 *
*	Function Name: password_isCorrect																		 *
*																																			 *
* Behaviour: the function used for checking if the password get from   *
*						 the user is true or not acorrding to saved pass.					 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: void 							  													     *
*																																			 *
***********************************************************************/
void password_isCorrect(void);

/***********************************************************************
*																																			 *
*	Function Name: password_isCorrect																		 *
*																																			 *
* Behaviour: the function used for checking if the password get from   *
*						 the user is true or not acorrding to saved pass.					 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: void 							  													     *
*																																			 *
***********************************************************************/
void servoMotor_Action(void);

/***********************************************************************
*																																			 *
*	Function Name: LCD_homeScreen   																		 *
*																																			 *
* Behaviour: the function used for displaying the home screen					 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: void 							  													     *
*																																			 *
***********************************************************************/
void LCD_homeScreen(void);

void main ()
{	
	/* Local var for reading sensor value */
	unsigned char IR_Read; 
	/* Init LCD to be able to display */
	LCD_init();
	/* Prepare timer 1 to start */
	Timer0_Start();
	/* Init Servo at inital angle */
	SERVO_init();
	/* Init uart for serial communication */
	uart_Init();
	/* Put the initial state of buzzer is off */
	BUZZER_status(BUZZER_OFF);
	/* Put the initial state of red led is off */
	RED_ledStatus(LED_OFF);
	/* Put the initial state of yellow led is off */
	YELLOW_ledStatus(LED_OFF);
	/* Put the initial state of green led is off */
	GREEN_ledStatus(LED_OFF);
	/* Function to display the home screen */
	LCD_homeScreen();
	
	for(;;){
		  /* Store the read of teh sensor in this variable and check on it */
		IR_Read = IR_readStatus();
	
		if( IR_Read == IR_DETECT )
		{
		/* If sensor detect there is a person it will change screen to password screen */
		LCD_clearScreen();	
		LCD_displayString("Enter Password:");
		LCD_moveCursor(1,0);
			
		/* Call this function for receiving password */
		receive_PasswordfromUser();
		password_isCorrect();
		
		/* Check on the password was matched to saved password */
		if( correct_pass_flag == 0)
		{
			/* Make sure that the counter still contains it is value if the user enters matched password */
			num_ofCorrect_Password = 3;
			/* Function for making the servo motor rotate */
			servoMotor_Action();
			/* Send to internal system 'S' as Start your System */
			uart_Sendbyte('S');
			delayms(1000);
			}
		else
		{
			/* Decrement the counter by 1 due to the wrong password */
			num_ofCorrect_Password--;
			/* This case means that the useer enter the wrong password */
			RED_ledStatus(LED_ON);
			/* Enter this loop if the password is not true*/
			while( num_ofCorrect_Password != 0 )
			{
			
			LCD_clearScreen();
			
			LCD_moveCursor(0,4);
			LCD_displayString("Wrong");
			LCD_moveCursor(1,3);
			LCD_displayString("Password");
			delayms(150);
			
			RED_ledStatus(LED_OFF);
			YELLOW_ledStatus(LED_ON);
			
			LCD_clearScreen();
			LCD_displayString("Enter Password:");
			LCD_moveCursor(1,0);
			
			receive_PasswordfromUser();
			password_isCorrect();
			
			if( correct_pass_flag == 1)
			{
				num_ofCorrect_Password--;
			}
			else if( correct_pass_flag == 0)
			{
				reEnter_pass_flag = 1;
				num_ofCorrect_Password = 3;
				break;
			}
			else
			{
				/* Do No Thing */
			}		 
			}//End of While
		}//End of else if the password is not true

		if(reEnter_pass_flag == 1 )
		{
			/* Reset the flag to be able to enter here again */
			reEnter_pass_flag = 0;
			/* Turn off the yellow led and turn on green led means password is correct */
			YELLOW_ledStatus(LED_OFF);
			/* Function for making the servo motor rotate */
			servoMotor_Action();
			/* After finishing return to the home page */
		  LCD_homeScreen();
			/* Send to internal system 'S' as Start your features */
			uart_Sendbyte('S');
			delayms(1000);
		}
			/* 
			 * If the user enter the password wrong for 3 times 
			 * the program should stuck here to indicate that is 
			 * an error happen.
			 *
			 * NOTE: If the program reach here the real user should 
			 *       restart the system again, and reset the password.
			 */
			while(num_ofCorrect_Password == 0)
			{
				RED_ledStatus(LED_ON);
				YELLOW_ledStatus(LED_ON);
				GREEN_ledStatus(LED_ON);
				BUZZER_status(BUZZER_ON);
			}
		}
		else
		{
			LCD_homeScreen();
		}//End of IR sesnor check condition
		
	}//End of main infinte loop
	
	
}//End of Main


/****************************************************
*							Some Needed Functions									*
****************************************************/

void receive_PasswordfromUser(void)
{
	unsigned char i;
	
	for( i = 0; i < 4; i++)
	{
		entered_pass[i] = 0;
	}
	
	for( i = 0; i < 4; i++)
	{		
		entered_pass[i] = KEYPAD_getPressedKey();
				
		if(entered_pass[i] >= '0' && entered_pass[i]<= '9')
		{
			LCD_displayCharacter(entered_pass[i]);
			delayms(50);	
		}
		else
		{
			i--;
		}
		delayms(50);		
	}

	while(KEYPAD_getPressedKey()!= '#');
}


void password_isCorrect(void)
{
	unsigned char i;
	
	correct_pass_flag = 0;
	
	for( i = 0; i < 4 ; i++ )
		{
			if(entered_pass[i] != saved_pass[i])// 1331 != 1221
			{
				/* if the password not true the flag will rise */
				 correct_pass_flag = 1;
			}
		}
		
}

void servoMotor_Action(void)
{
			/* Make sure that the counter still contains it is value if the user enters matched password */
			num_ofCorrect_Password = 3;
			/* This case means that the useer enter the correct password */
			GREEN_ledStatus(LED_ON);
			LCD_clearScreen();
			delayms(50);
			
			/* Dispaly that the door is opened and open the door */
		 LCD_moveCursor(0,6);
		 LCD_displayString("Door");
		 LCD_moveCursor(1,4);
		 LCD_displayString("is Opened");
	
		 SERVO_rotateDegree(0XF8,0X30);
		 delayms(500);
		 SERVO_rotateDegree(0XFA,0X24);
		 delayms(1500);
		 
		 /* Dispaly tehat the door is closed and close the door */
		 LCD_clearScreen();
		 LCD_moveCursor(0,6);
		 LCD_displayString("Door");
		 LCD_moveCursor(1,4);
		 LCD_displayString("is Closed");
		 
		 SERVO_rotateDegree(0xFC,0X2C);
		 delayms(500);
		 SERVO_rotateDegree(0XFA,0X24);
		 delayms(500);
		 
		 /*Finally, turn off the green led because the door was closed*/
		 GREEN_ledStatus(LED_OFF);
		 
		 LCD_clearScreen();
}

void LCD_homeScreen(void)
{
			LCD_moveCursor(0,4);
		  LCD_displayString("Welcome -_-");
	    LCD_moveCursor(1,0);
	    LCD_displayString("Security Boot x");
}