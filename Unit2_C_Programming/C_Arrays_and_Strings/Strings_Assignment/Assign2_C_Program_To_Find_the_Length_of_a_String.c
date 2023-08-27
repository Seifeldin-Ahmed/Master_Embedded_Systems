/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Find_the_Length_of_a_String.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : you can use standard library function strlen() to find the length of a string
 *                but, this program computes the length of a string manually without using strlen() function ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=0;
	char arr[20];
	printf("Enter a string: ");
	fflush(stdout);  fflush(stdin);
	scanf("%s",arr);

    while(arr[i]!=0)
    {
    	i++;
    }

	printf("Length of string: %d",i);

	return 0;
}
