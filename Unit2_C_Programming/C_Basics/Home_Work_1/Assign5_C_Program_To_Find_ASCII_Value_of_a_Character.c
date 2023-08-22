/********************************************************************************************************************************************/
/*  Name	    : Assign5_C_Program_To_Find_ASCII_Value_of_a_Character.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Find ASCII Value of a Character entered by user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input;
    printf("Enter a character: ");
    fflush(stdout);  fflush(stdin);
    scanf("%c",&input);
    printf("\nASCII value of %c = %d",input,input);
	return 0;
}
