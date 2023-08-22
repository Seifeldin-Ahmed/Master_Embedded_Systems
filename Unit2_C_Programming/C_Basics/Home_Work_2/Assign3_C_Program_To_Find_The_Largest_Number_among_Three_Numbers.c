/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Find_The_Largest_Number_among_Three_Numbers.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Find The Largest Number among  Three Numbers ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1,num2,num3 , max;

    printf("Enter three numbers: ");
    fflush(stdout);  fflush(stdin);
    scanf("%d %d %d",&num1,&num2,&num3);

    max = num1 ;
    if(num2>max)
    	max = num2;
    if(num3>max)
    	max = num3;
    printf("Largest Number = %d",max);
    return 0;
}
