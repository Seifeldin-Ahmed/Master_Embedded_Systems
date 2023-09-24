/********************************************************************************************************************************************/
/*  Name	    : Assign4_C_Program_To_Store_Information_of_students_using_structure.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Store Information(name, roll and marks) of students using structure ----> using(C89)
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
 struct Sstudent student[10];
 int i;
 /****************************** Input Section **************************/
 printf("Enter information of a students: \n");

 for(i=0 ; i<10 ; i++)
 {
	 student[i].roll = i+1;
	 printf("For roll number %d\n", student[i].roll);

	 printf("Enter name: ");
	 fflush(stdin); fflush(stdout);
	 scanf("%s",student[i].name);

	 printf("Enter marks: ");
	 fflush(stdin); fflush(stdout);
	 scanf("%f",&student[i].mark);
 }
 /****************************** Output Section **************************/
 printf("\nDisplaying Information of students : \n");
 for(i=0 ; i<10 ; i++)
 {
	 printf("Information for roll number %d:\n",student[i].roll);
	 printf("Name: %s\nMarks: %0.1f\n",student[i].name,student[i].mark);
 }

	return 0;
}


