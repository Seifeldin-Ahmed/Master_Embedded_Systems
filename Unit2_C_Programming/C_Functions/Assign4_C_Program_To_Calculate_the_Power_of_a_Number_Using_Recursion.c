/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Calculate_the_Power_of_a_Number_Using_Recursion.c
 *  Created on  : Sep 1, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Calculate the Power of a Number Using Recursion ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>

int Calculate_power(int base ,int power );

int main()
{
  int base,power;
  printf("Enter base number: ");
  fflush(stdin); fflush(stdout);
  scanf("%d",&base);

  printf("Enter power number(positive integer): ");
  fflush(stdin); fflush(stdout);
  scanf("%d",&power);
  printf("%d ^ %d = %d",base,power,Calculate_power(base,power));
	return 0;
}

int Calculate_power(int base ,int power )
{
	if(base == 1)
		return 1;
	else if(power == 1)
		return base;
	else
	    return base * Calculate_power(base,power-1);
}
