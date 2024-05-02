/***********************************************************************
*																																			 *					 
*	File Name: uart.c														 								         *
*																																			 *
* Subject: the uart source file contains the flow of code  			       *						 
*																																			 *	 
*	Date: 15-4-2024																								 			 *
*																																       *
* Created By: Group 1 -> Embedded System Course												 *											 
*																																			 *
***********************************************************************/

#include <uart.h>
#include <reg51.h>

void uart_Init(void)
{
	/* Wrok with default UART that is 8_bit _data frame*/
	SCON = 0x50;
	/* Down the tarnsmit and receive flag  */
	T1 = 0; 
	RI = 0;
  /* SMOD reigster put 0 in last _bit*/
	PCON &= ~(1<<7);
	/* Using timer 1 in TMOD*/
	TMOD |= (1<<5);
	/* Set timer 1 to use buad rate 9600 */
	TH1 = 253;
	/* Enable timer 1 to count */
	TR1 =1;
}

void uart_Sendbyte(unsigned char ch)
{
	
	SBUF  = ch;
	
	while(TI != 1);
	
	TI = 0;
	
}

unsigned char uart_Receivebyte(void)
{

	unsigned char buff;
	
	while(RI != 1);
	
	buff = SBUF;
	
	RI = 0;
	
	return buff;
}