/********************************************************************************************************************************************/
/*  Name	    : Assign5_C_Program_To_Check_Whether_a_Character_is_an_alphabet_or_not.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Check Wheter a character is an alphabet or not ----> using(C89)
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

     if((input>'a' && input < 'z' ) || (input>'A' && input < 'Z' ) )
    	 printf("\n%c is an alphabet",input);
     else
    	 printf("\n%c is not an alphabet",input);

    return 0;
}
