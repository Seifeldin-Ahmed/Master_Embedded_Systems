/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Check_Whether_a_Number_is_Even_or_Odd.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Check Wheter a Number is Even or Odd ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

    printf("Enter an Integer you want to check: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d",&num);

    if(num%2 == 0)
        printf("\n %d is even",num);
    else
    	printf("\n%d is odd",num);

    return 0;
}
