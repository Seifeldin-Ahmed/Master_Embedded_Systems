/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Print_a_string_in_reverse_using_a_pointer.c
 *  Created on  : Oct 4, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : C program to print a string in reverse using pointer ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	char arr[50]={0},i;
    char * ptr = arr+49;
	printf("Pointer: Print a string in reverse order :\n");
	printf("-----------------------------------------\n");
    printf("Input a string: ");
    fflush(stdin); fflush(stdout);
    scanf("%s",arr);
    fflush(stdin); fflush(stdout);
    for(i=0;i<50;i++)
    {
      if(*ptr!=0)
      printf("%c",*ptr);
      ptr--;
    }
	return 0;
}


