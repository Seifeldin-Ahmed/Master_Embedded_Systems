/********************************************************************************************************************************************/
/*  Name	    : Assign5_C_Program_To_find_area_of_a_circle_passing_arguments_to_macros.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Find Area of a circle, Passing arguments to macros ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define area(radius)    (PI*radius*radius)
int main()
{
 int radius;
 float area;
 /****************************** Input Section **************************/
 printf("Enter the radius: ");
 fflush(stdin); fflush(stdout);
 scanf("%d",&radius);

 /****************************** Calculate Area **************************/
 area = area(radius);
 printf("Area= %0.2f",area);

	return 0;
}


