/********************************************************************************************************************************************/
/*  Name	    : app.c
 *  Created on  : Novamber 23, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 */
/********************************************************************************************************************************************/

#include "uart.h"

unsigned char string_buffer1[100]= "learn-in-depth:seif";
const unsigned char string_buffer2[100]= "learn-in-depth:seif";

int main()
{
	Uart_Send_String(string_buffer1);
	return 0 ;
}