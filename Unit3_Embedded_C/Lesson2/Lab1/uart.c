/********************************************************************************************************************************************/
/*  Name	    : uart.c
 *  Created on  : Novamber 23, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 */
/********************************************************************************************************************************************/

#include "uart.h"

#define UART0OR 			*(volatile unsigned int* const)(0x101f1000)     


void Uart_Send_String(unsigned char * P_tx_string)
{
	while (*P_tx_string != '\0')
	{
		UART0OR = (unsigned int)(*P_tx_string);
		P_tx_string++;
	}
}