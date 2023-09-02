/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Reverse_a_Sentence_Using_Recursion.c
 *  Created on  : Sep 1, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Reverse a Sentence Using Recursion ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>

void Reverse_Sentence(void);

int main()
{
  printf("Enter a sentence: ");
  fflush(stdin); fflush(stdout);
  Reverse_Sentence();

	return 0;
}

void Reverse_Sentence(void)
{
   char c;
   scanf("%c",&c);
   if(c!='\n')
   {
	   Reverse_Sentence();
	   printf("%c",c);
   }

}
