/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Print_the_elements_of_an_array_in_reverse_order.c
 *  Created on  : Oct 4, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : C program to print the elements of an array in reverse order ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[15],size,i;
	int * ptr;
	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);

	printf("Input %d number of elements in the array: \n",size);
	fflush(stdin); fflush(stdout);
	ptr = arr;
	for(i=0;i<size;i++)
	{
	   printf("element - %d : ",i+1);
	   fflush(stdin); fflush(stdout);
	   scanf("%d",ptr);
	   ptr++;
	}

	printf("The elements of array in reverse order are : \n");
	ptr = arr + size - 1; /* size -1 to get the index */
	for(i=size;i>0;i--)
	{
	   printf("element - %d : %d\n",i,*ptr);
	   ptr--;
	}
	return 0;
}




