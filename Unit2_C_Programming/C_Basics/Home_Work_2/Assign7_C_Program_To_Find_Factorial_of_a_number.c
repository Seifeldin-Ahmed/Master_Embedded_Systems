/********************************************************************************************************************************************/
/*  Name	    : Assign7_C_Program_To_Find_Factorial_of_a_number.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Find Factorial of a number ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num , i , factorial=1;

    printf("Enter an Integer: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d",&num);

    if(num<0)
    	printf("Error!!! Factorial of negative number doesn't exist");
    else if (num ==0)
    	printf("Factorial = %d",1);
    else
     {
    	for(i=1 ; i<= num ; i++)
    		factorial *=i;
    	printf("Factorial = %d",factorial);
     }
    return 0;
}
