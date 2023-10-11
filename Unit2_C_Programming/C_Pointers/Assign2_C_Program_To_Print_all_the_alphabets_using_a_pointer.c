/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Print_all_the_alphabets_using_a_pointer.c
 *  Created on  : Oct 4, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : C program to Print all the alphabets using a pointer ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alpha[26], i;
	char* pointer = alpha;
	for (i=0;i<26;i++)
	{
	  *pointer='A'+i;
	   pointer++;
	}
    pointer = alpha;
	printf("The Alphabets are:\n");
	for (i=0;i<26;i++)
	{
	  printf("%c  ",*pointer);
	  pointer++;
	}

	return 0;
}




