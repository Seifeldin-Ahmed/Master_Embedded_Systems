/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Multiply_two_Floating_Point_Numbers.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Multiply two Floating points entered by user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num1,num2;
    printf("Enter two numbers: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f %f",&num1,&num2);
    printf("\nYou entered: %f",num1*num2);
	return 0;
}
