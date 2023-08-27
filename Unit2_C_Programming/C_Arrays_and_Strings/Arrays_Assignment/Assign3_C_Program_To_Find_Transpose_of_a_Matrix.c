/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Find_Transpose_of_a_Matrix.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Find Transpose of a Matrix ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row,col,i,j;
  float arr[10][10] , Transpose[10][10];

  printf("Enter rows and columns of matrix: ");
  fflush(stdin); fflush(stdout);
  scanf("%d %d",&row,&col);
 /*************************************** Enter the elements of the Matrix *********************/
  printf("Enter elements of matrix: \n");
  for(i=0 ;i< row ; i++)
  {
	  for(j=0 ; j< col ; j++)
	  {
		  printf("Enter element a%d%d: ",i+1,j+1);
		  fflush(stdin); fflush(stdout);
          scanf("%f",&arr[i][j]);
	  }
  }
 /******************************************** Print the Entered Matrix *************************/
  printf("Entered Matrix: \n");
  for(i=0 ;i< row ; i++)
  {
	  for(j=0 ; j< col ; j++)
	  {
		  printf("%0.1f    ",arr[i][j]);

	  }
	  printf("\n");
  }

  /********************************************** Transpose ***********************************/
  printf("Transpose Of Matrix: \n");
  for(i=0 ;i< row ; i++)
  {
	  for(j=0 ; j< col ; j++)
	  {
		  Transpose[j][i] = arr[i][j];
	  }
  }
 /******************************************* Print the Transpose ******************************/
  for(i=0 ;i< col ; i++)
  {
	  for(j=0 ; j< row ; j++)
	  {
		  printf("%0.1f    ",Transpose[i][j]);
	  }
	  printf("\n");
  }



  return 0;
}
