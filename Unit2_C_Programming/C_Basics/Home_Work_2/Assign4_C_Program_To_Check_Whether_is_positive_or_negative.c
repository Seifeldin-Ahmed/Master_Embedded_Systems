/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Check_Whether_is_positive_or_negative.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Check Wheter a Number is positive or negative ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num;

    printf("Enter a number: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f",&num);

    if(num > 0)
        printf("\n %f is positive",num);
    else if (num < 0)
    	  printf("\n %f is negative",num);
    else
    	  printf("\n %f is zero",num);

    return 0;
}
