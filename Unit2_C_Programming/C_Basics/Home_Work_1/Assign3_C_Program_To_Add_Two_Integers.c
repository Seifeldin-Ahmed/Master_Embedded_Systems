/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Add_Two_Integers.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Add two integers entered by the user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1,num2;
    printf("Enter two integers: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d %d",&num1,&num2);
    printf("\nSum: %d",num1+num2);
	return 0;
}
