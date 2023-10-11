/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Demonstrate_How_to_handle_the_pointers_in_the_program.c
 *  Created on  : Oct 4, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : C program to demonstrate how to handle the pointers in the program ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m = 29;
	int* ab = NULL;
	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d\n",m);


	printf("Now ab is assigned with the address of m\n");
	ab = &m;
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	printf("The value of m assigned to 34 now\n");
    m=34;
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Content of pointer ab : %d\n",*ab);

	printf("The pointer varaible ab is assigned with the value 7 now\n");
    *ab=7;
	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d\n",m);
	return 0;
}




