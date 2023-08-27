/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Insert_an_element_in_an_Array.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Insert an element in an array ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number_of_elements , inserted_element , inserted_location , i;
   int arr[10];
   printf("Enter no of elements: ");
   fflush(stdin); fflush(stdout);
   scanf("%d",&number_of_elements);
   while(number_of_elements>=10 || number_of_elements<=0)
   {
	   printf("Error! number of elemetns should be between (1,9). \n ");
	   printf("Enter no of elements again: ");
	   fflush(stdin); fflush(stdout);
	   scanf("%d",&number_of_elements);
   }

   printf("enter the elements: ");
   fflush(stdin); fflush(stdout);
   for(i=0 ; i<number_of_elements; i++)
    	scanf("%d",&arr[i]);

   printf("Enter the element to be inserted: ");
   fflush(stdin); fflush(stdout);
   scanf("%d",&inserted_element);

   printf("Enter the location: ");
   fflush(stdin); fflush(stdout);
   scanf("%d",&inserted_location);

   for(i=number_of_elements-1 ; i>=inserted_location-1; i--)
        arr[i+1] = arr[i]; /*shift the elements before you insert new item*/

   arr[inserted_location-1]= inserted_element; /*inserted_location-1: because (inserted_location) is a position but (inserted_location-1) is the index*/

   for(i=0 ; i<number_of_elements+1; i++)
	   printf("%d  ",arr[i]);

	return 0;
}
