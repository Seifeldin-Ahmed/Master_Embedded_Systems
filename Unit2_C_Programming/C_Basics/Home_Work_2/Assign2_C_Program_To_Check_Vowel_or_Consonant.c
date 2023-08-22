/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Check_Vowel_or_Consonant.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Check Vowel or Consonant ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input;

    printf("Enter an alphabet: ");
    fflush(stdout);  fflush(stdin);
    scanf("%c",&input);

    switch(input)
    {
    	case 'a':   printf("%c is a vowel.",input) ; break;
    	case 'e':   printf("%c is a vowel.",input) ; break;
    	case 'i':   printf("%c is a vowel.",input) ; break;
    	case 'o':   printf("%c is a vowel.",input) ; break;
    	case 'u':   printf("%c is a vowel.",input) ; break;
    	default :   printf("%c is a consonant.",input) ; break;
    }

    return 0;
}
