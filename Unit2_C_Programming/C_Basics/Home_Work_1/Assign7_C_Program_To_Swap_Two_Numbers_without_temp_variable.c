/********************************************************************************************************************************************/
/*  Name	    : Assign7_C_Program_To_Swap_Two_Numbers_without_temp_variable.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Swap Two Numbers entered by user without temp variable ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a,b;

    printf("Enter value of a: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f",&a);

    printf("\nEnter value of b: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f",&b);

    a = a + b; 
    b = a - b; /*          b = a - b   --->       b = a + b - b                 --->     b = a                                           */
    a = a - b; /*          a = a - b   --->       a = a + b - b (b now = a)     --->     a = a + b - a       --->       a = b            */

    printf("\nAfter swapping, value of a = %f",a);
    printf("\nAfter swapping, value of b = %f",b);
	return 0;
}
