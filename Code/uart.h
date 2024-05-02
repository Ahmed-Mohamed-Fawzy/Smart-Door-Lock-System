#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>

sbit RX_pin = P3^0;
sbit TX_pin = P3^1;

/***********************************************************************
*																																			 *
*	Function Name: uart_Init																						 *
*																																			 *
* Behaviour: the function used for init the uart driver								 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: void																								 *
*																																			 *
***********************************************************************/
void uart_Init(void);

/***********************************************************************
*																																			 *
*	Function Name: uart_Sendbyte																				 *
*																																			 *
* Behaviour: the function used for sending bytes by uart.							 *
*																																			 *
*	Input Paramter: character need to sent			 												 *
*																																       *
* Output Paramter: void																								 *
*																																			 *
***********************************************************************/
void uart_Sendbyte(unsigned char ch);

/***********************************************************************
*																																			 *
*	Function Name: uart_Receivebyte																			 *
*																																			 *
* Behaviour: the function used for receiving bytes by using  uart			 *
*																																			 *
*	Input Paramter: void																								 *
*																																       *
* Output Paramter: character indicates that data received	  					 *
*																																			 *
***********************************************************************/
unsigned char uart_Receivebyte(void);




#endif