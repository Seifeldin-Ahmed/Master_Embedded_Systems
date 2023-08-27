/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Find_the_Frequency_of_Characters_in_a_String.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : This program asks user to enter a string and a character, and this program checks
 *                how many times that character is repeated in the string entered by user ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char arr[50] , character;
	int i=0,freq=0;
    printf("Enter a string:");
    fflush(stdout); fflush(stdin);
    gets(arr);

    printf("Enter a character to find frequency: ");
    fflush(stdout); fflush(stdin);
    scanf("%c",&character);

/********************* Find The frequency of the entered character ****************/
    while(arr[i]!=0)
    {
    	if(arr[i] == character)
              freq++;
    	i++;
    }
    printf("Frequency of %c = %d",character,freq);

    return 0;
}
