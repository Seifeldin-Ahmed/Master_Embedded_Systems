/********************************************************************************************************************************************/
/*  Name	    : Assign1_C_Program_To_Store_Information_of_a_student_using_structure.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Store Information(name, roll and marks) of a student using structure ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Sstudent{
	char name[50];
	int roll     ;
	float mark   ;
};
int main()
{
 struct Sstudent object;
 /****************************** Input Section **************************/
 printf("Enter information of a students: \n");

 printf("Enter name: ");
 fflush(stdin); fflush(stdout);
 scanf("%s",object.name);

 printf("Enter roll number: ");
 fflush(stdin); fflush(stdout);
 scanf("%d",&object.roll);

 printf("Enter marks: ");
 fflush(stdin); fflush(stdout);
 scanf("%f",&object.mark);

 /****************************** Output Section **************************/
 printf("Displaying Information: \n");
 printf("name: %s \nRoll: %d \nMarks: %0.2f",object.name,object.roll,object.mark);


	return 0;
}


