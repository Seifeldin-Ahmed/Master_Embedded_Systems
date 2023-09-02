/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Find_Prime_Numbers_Between_two_Intervals.c
 *  Created on  : Sep 1, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Find Prime Numbers Between two Intervals by Making User-defined Function ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>

int Check_Prime(int number );

int main()
{
  int i,num1,num2;
  printf("Enter two numbers(intervals: ");
  fflush(stdin); fflush(stdout);
  scanf("%d %d",&num1,&num2);
  printf("Prime numbers between %d and %d are: ",num1,num2);
  for(i=num1+1 ; i<num2 ; i++)
  {
	  if(Check_Prime(i))
		  printf("%d  ",i);
  }
	return 0;
}

int Check_Prime(int number )
{
	int i,count=0;
	for (i = 2; i <= number; i++) {
	      if (number % i == 0) {
	          count++;
	      }
	  }
    if(count==1)
    	return 1 ; /*true*/
    else
    	return 0 ; /*false*/
}
