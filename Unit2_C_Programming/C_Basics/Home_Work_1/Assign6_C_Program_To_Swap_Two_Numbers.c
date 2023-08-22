/********************************************************************************************************************************************/
/*  Name	    : Assign6_C_Program_To_Swap_Two_Numbers.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Swap Two Numbers entered by user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a,b,temp;

    printf("Enter value of a: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f",&a);

    printf("\nEnter value of b: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f",&b);

    temp = a;
    a = b;
    b =temp;
    printf("\nAfter swapping, value of a = %f",a);
    printf("\nAfter swapping, value of b = %f",b);
	return 0;
}
