/********************************************************************************************************************************************/
/*  Name	    : Assign6_C_Program_To_Calculate_Sum_Of_Natural_Numbers.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Calculate Sum Of Natural Numbers ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, i, sum=0;

    printf("Enter an Integer: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d",&num);

   for(i=1 ; i<=num ; i++)
        sum +=i;

   printf("Sum: %d",sum);

    return 0;
}
