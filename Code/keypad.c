/***********************************************************************
*																																			 *					 
*	File Name: keypad.c													 								         *
*																																			 *
* Subject: the keypad source file contains the keypad functions   	   *						 														  									 
*																																			 *
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <keypad.h>
#include <reg51.h>

/*Keypad Function Definations*/
unsigned char  KEYPAD_getPressedKey(void)
{
	
	
	for(;;)
	{
	
	KEYPAD_COL_Pin_1 = 1;
  KEYPAD_COL_Pin_2 = 1;
  KEYPAD_COL_Pin_3 = 1;
  KEYPAD_COL_Pin_4 = 1;
	delayms(50);
		
  KEYPAD_ROW_Pin_1 = 0;
  KEYPAD_ROW_Pin_2 = 1;
  KEYPAD_ROW_Pin_3 = 1;
  KEYPAD_ROW_Pin_4 = 1;
	
  if(KEYPAD_COL_Pin_1==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_1==0);
		return '1';
	}
	
  if(KEYPAD_COL_Pin_2==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_2==0);
		return '2';
	}
  if(KEYPAD_COL_Pin_3==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_3==0);
		return '3';
	}
  if(KEYPAD_COL_Pin_4==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_4==0);
		return 'A';
	}
	
  KEYPAD_ROW_Pin_1=1;
  KEYPAD_ROW_Pin_2=0;
  KEYPAD_ROW_Pin_3=1;
  KEYPAD_ROW_Pin_4=1;
	
  if(KEYPAD_COL_Pin_1==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_1==0);
		return '4';
	}
  if(KEYPAD_COL_Pin_2==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_2==0);
		return '5';
	}
  
	if(KEYPAD_COL_Pin_3==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_3==0);
		return '6';
	}
  
	if(KEYPAD_COL_Pin_4==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_4==0);
		return 'B';
	}
	
  KEYPAD_ROW_Pin_1=1;
  KEYPAD_ROW_Pin_2=1;
  KEYPAD_ROW_Pin_3=0;
  KEYPAD_ROW_Pin_4=1;
	
  if(KEYPAD_COL_Pin_1==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_1==0);
		return '7';
	}
  
	if(KEYPAD_COL_Pin_2==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_2==0);
		return '8';
	}
  
	if(KEYPAD_COL_Pin_3==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_3==0);
		return '9';
	}
  
	if(KEYPAD_COL_Pin_4==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_4==0);
		return 'C';
	}
	
  KEYPAD_ROW_Pin_1=1;
  KEYPAD_ROW_Pin_2=1;
  KEYPAD_ROW_Pin_3=1;
  KEYPAD_ROW_Pin_4=0;
	
  if(KEYPAD_COL_Pin_1==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_1==0);
		return '*';
	}
  
	if(KEYPAD_COL_Pin_2==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_2==0);
		return '0';
	}
  
	if(KEYPAD_COL_Pin_3==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_3==0);
		return '#';
	}
  if(KEYPAD_COL_Pin_4==0)
	{
		delayms(50);
		while(KEYPAD_COL_Pin_4==0);
		return 'D';
	}
	}
}
