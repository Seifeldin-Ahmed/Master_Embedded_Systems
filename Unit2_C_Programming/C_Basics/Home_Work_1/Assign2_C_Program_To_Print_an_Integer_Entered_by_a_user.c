/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Print_an_Integer_Entered_by_a_user.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Print a number entered by user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input;
    printf("Enter a integer: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d",&input);
    printf("\nYou entered: %d",input);
	return 0;
}
