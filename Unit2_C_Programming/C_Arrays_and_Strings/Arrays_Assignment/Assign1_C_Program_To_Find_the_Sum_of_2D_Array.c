/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Find_the_Sum_of_2D_Array.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Find the sum of two matrix of order 2*2 entered by the user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
  /************************** Vairables definition and declaration ************/
    float a[2][2];
    float b[2][2];
    float sum[2][2];
    int row,col;

 /********************************* First Matrix ******************************/
	printf("Enter the elements of 1st matrix: \n");
    for(row=0 ; row < 2; row++)
    {
       for(col=0; col< 2 ; col++)
       {
			printf("Enter a%d%d: ",row+1,col+1);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&a[row][col]);
       }
    }

 /******************************** Second Matrix *******************************/
	printf("Enter the elements of 2st matrix: \n");
    for(row=0 ; row < 2; row++)
    {
       for(col=0; col< 2 ; col++)
       {
			printf("Enter b%d%d: ",row+1,col+1);
			fflush(stdin);  fflush(stdout);
			scanf("%f",&b[row][col]);
       }
    }

 /************************************** Sum of the two matrix ********************/
    for(row=0 ; row < 2; row++)
    {
       for(col=0; col< 2 ; col++)
       {
    	  sum[row][col] = a[row][col] + b[row][col];
       }
    }
    printf("Sum Of Matrix: \n");
    for(row=0 ; row < 2; row++)
    {
       for(col=0; col< 2 ; col++)
       {
    	  printf("%0.1f\t",sum[row][col]);
       }
       printf("\n");
    }

  return 0;
}
