/********************************************************************************************************************************************/
/*  Name	    : Assign5_C_Program_To_Search_an_element_in_Array.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Search an element in Array ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
  int number_of_elements , i , arr[10] , element_to_be_searched;

  /*************************** Enter number of elements between (1,10) *****************/

  printf("Enter no of elements: ");
  fflush(stdin); fflush(stdout);
  scanf("%d",&number_of_elements);

  while(number_of_elements>10 || number_of_elements<=0)
  {
	   printf("Error! number of elemetns should be between (1,10).\n ");
	   printf("Enter no of elements again: ");
	   fflush(stdin); fflush(stdout);
	   scanf("%d",&number_of_elements);
  }

  /******************************************** Enter elements **************************/

  printf("Enter the elements: ");
  fflush(stdin); fflush(stdout);
  for( i=0 ; i<number_of_elements ; i++)
	  scanf("%d",&arr[i]);

  /************************************ Enter element to be searched *******************/

  printf("Enter the element to be searched: ");
  fflush(stdin); fflush(stdout);
  scanf("%d",&element_to_be_searched);

  /******************************************** Search element *************************/
  for( i=0; i<number_of_elements ; i++)
  {
	  if(arr[i]==element_to_be_searched)
	  {
		  printf("Number found at the location = %d\n",i+1);
		  break;
	  }
  }

  if(i==number_of_elements)
  {
	  printf("Number Not Found\n");
  }
  return 0;
}
