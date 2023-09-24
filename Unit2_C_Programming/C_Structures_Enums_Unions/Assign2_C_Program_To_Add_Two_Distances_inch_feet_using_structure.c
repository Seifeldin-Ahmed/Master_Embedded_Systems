/********************************************************************************************************************************************/
/*  Name	    : Assign2_C_Program_To_Add_Two_Distances_inch_feet_using_structure.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Add Two Distances(in inch-feet) System Using structure ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Sdistance{
	int feet ;
	float inch ;
};
int main()
{
 struct Sdistance object1, object2, sum;
 /****************************** Input Section **************************/
 printf("Enter information for 1st distance: \n");

 printf("Enter feet: ");
 fflush(stdin); fflush(stdout);
 scanf("%d",&object1.feet);

 printf("Enter inch: ");
 fflush(stdin); fflush(stdout);
 scanf("%f",&object1.inch);

 printf("Enter information for 2st distance: \n");

 printf("Enter feet: ");
 fflush(stdin); fflush(stdout);
 scanf("%d",&object2.feet);

 printf("Enter inch: ");
 fflush(stdin); fflush(stdout);
 scanf("%f",&object2.inch);
 /**************************** Calculate Distance ************************/
 sum.feet = object1.feet + object2.feet;
 sum.inch = object1.inch + object2.inch;
 if(sum.inch > 12)
 {
	 sum.feet++;
	 sum.inch -=12;
 }
 /****************************** Output Section **************************/
 printf("Sum of distances = %d - %0.2f", sum.feet, sum.inch);
	return 0;
}


