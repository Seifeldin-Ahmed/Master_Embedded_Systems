/********************************************************************************************************************************************/
/*  Name	    : Assign5_C_Program_To_show_a_pointer_to_an_array_which_contents_are_pointer_to_structre.c
 *  Created on  : Oct 11, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : C program to show a pointer to an array which contents are pointer to structure----> using(C89)
 */
/********************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char* name;
	int id;
}Employee;

int main()
{
	Employee obj1 = {"Alex",1002};
	Employee obj2 = {"seif",2300};
	Employee* arr[]={&obj1,&obj2}; /*array of pointer to structure*/
	Employee* (*ptr)[2] = &arr;   /*pointer to array of 2 elements of type pointer to stucture*/

	printf("  Employee Name : %s  \n",(**(*ptr+1)).name);
	printf("---------------  Explanation  --------------\n");
	printf("    (**(*ptr+1)).name                              	 	   \n");
	printf("    (**(*&arr+1)).name    	   as ptr = &arr               \n");
	printf("    (**(arr+1)).name      	   from rule *&pt = pt         \n");
	printf("    (*arr[1]).name       	   from rule *(arr+1) = arr[1] \n");
	printf("    (*&obj2).name                  as arr[1] = &obj1           \n");
	printf("    (obj2).name = \"seif\"           from rule *&ptr = ptr       \n");


	printf("\n\n Employee ID : %d  \n",(*(*ptr+1))->id);
	printf("---------------  Explanation  --------------\n");
	printf("    (*(*ptr+1))->id                             	 	   \n");
	printf("    (*(*&arr+1))->id    	   as ptr = &arr               \n");
	printf("    (*(arr+1))->id      	   from rule *&pt = pt         \n");
	printf("    (arr[1])->id       		   from rule *(arr+1) =arr[1]  \n");
	printf("    (*arr[1]).id                   from rule -> = (*)          \n");
	printf("    (*&obj2).id                    as arr[1] = &obj1           \n");
	printf("    (obj2).id = \"2300\"             from rule *&ptr = ptr       \n");

  return 0;
}


