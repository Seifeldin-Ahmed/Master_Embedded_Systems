/********************************************************************************************************************************************/
/*  Name	    : Assign6_C_Program_To_Find_Size_of_structure_and_union.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Find the size of structure and union ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>


union job{
	char name[32];
	float salary;
	int worker_no;
}u;

struct jpb1{
	char name[32];
	float salary;
	int worker_no;
}s;

int main()
{
  printf("size of union = %d",sizeof(u));          /* 32 byte */
  printf("\nsize of structure = %d",sizeof(s));    /* 40 byte */

	return 0;
}


