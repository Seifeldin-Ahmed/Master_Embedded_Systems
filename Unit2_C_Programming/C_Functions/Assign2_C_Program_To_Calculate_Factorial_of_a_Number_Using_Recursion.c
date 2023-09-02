/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Calculate_Factorial_of_a_Number_Using_Recursion.c
 *  Created on  : Sep 1, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Calculate Factorial of a Number Using Recursion ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>

int Find_Factorial(int number );

int main()
{
  int num;
  printf("Enter an positive integer: ");
  fflush(stdin); fflush(stdout);
  scanf("%d",&num);
  while(num<0)
  {
	  printf("you must enter an postive integer: ");
	  fflush(stdin); fflush(stdout);
	  scanf("%d",&num);

  }
  printf("Factorial of %d = %d",num,Find_Factorial(num));

	return 0;
}

int Find_Factorial(int number )
{
	if(number== 0 || number ==1)
		return 1;
	else
		return number * Find_Factorial(number-1);
}
