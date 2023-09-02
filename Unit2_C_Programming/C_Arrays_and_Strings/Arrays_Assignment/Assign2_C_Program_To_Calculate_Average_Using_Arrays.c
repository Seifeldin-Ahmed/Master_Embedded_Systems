/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Calculate_Average_Using_Arrays.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Calculate Average Using Arrays ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
  int number_of_data;
  int iterator;
  float arr[100] , sum=0;

  printf("Enter the number of data: ");
  fflush(stdin);fflush(stdout);
  scanf("%d",&number_of_data);
  while (number_of_data > 100 || number_of_data <= 0)
  {
	  printf("Number should be in range (1,100)\n");
	  printf("Enter the number of data again: ");
	  fflush(stdin); fflush(stdout);
	  scanf("%d", &number_of_data);
  }
  for(iterator  = 0; iterator < number_of_data; iterator ++)
  {
	  printf("Enter number: ");
	  fflush(stdin);fflush(stdout);
	  scanf("%f",&arr[iterator]);
	  sum += arr[iterator];
  }
  printf("Average = %0.2f", sum/number_of_data);

	return 0;
}
