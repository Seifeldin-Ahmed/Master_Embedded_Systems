/********************************************************************************************************************************************/
/*  Name	    : Assign3_C_Program_To_Add_Two_Complex_Numbers_By_Passing_Structure_to_a_Function.c
 *  Created on  : Sep 20, 2023
 *  Author	    : Seifeldin Ahmed Ismail
 *  Description : Add Two Complex Numbers By Passing Structure to a Function ----> using(C89)
 */
/********************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Scomplex_number{
	float real     ;
	float imaginary;
};

struct Scomplex_number add_complex_numbers(struct Scomplex_number num1,struct Scomplex_number num2);

int main()
{
 struct Scomplex_number object1, object2, result;
 /****************************** Input Section **************************/
 printf("For 1st complex number: \n");

 printf("Enter real and imaginary respectively: ");
 fflush(stdin); fflush(stdout);
 scanf("%f%f",&object1.real,&object1.imaginary);

 printf("For 2st complex number: \n");

 printf("Enter real and imaginary respectively: ");
 fflush(stdin); fflush(stdout);
 scanf("%f%f",&object2.real,&object2.imaginary);

 /****************************** Output Section **************************/
 result = add_complex_numbers(object1,object2);
 printf("Sum = %0.1f + %0.1fi",result.real,result.imaginary);
	return 0;
}


struct Scomplex_number add_complex_numbers(struct Scomplex_number num1,struct Scomplex_number num2)
{
	 struct Scomplex_number result;
	 result.real      = num1.real + num2.real;
	 result.imaginary = num1.imaginary + num2.imaginary ;
     return (result);
}
