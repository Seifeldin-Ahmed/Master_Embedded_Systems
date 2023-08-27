/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Reverse_String_without_library_function.c
 *  Created on  : Aug 27, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Reverse string without using library function except strlen() ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int last , first = 0;
	char arr[20] , temp;
	printf("Enter a string: ");
	fflush(stdout);  fflush(stdin);
	scanf("%s",arr);

	last = strlen(arr) - 1; /* -1 to get the index */
	while(first<last)
	{
		temp = arr[last];
		arr[last] = arr[first];
		arr[first] = temp;
		first++;
		last--;
	}
	printf("Reverse string is: %s",arr);

	return 0;
}
