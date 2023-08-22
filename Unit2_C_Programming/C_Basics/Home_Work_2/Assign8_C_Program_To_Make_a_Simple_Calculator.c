/********************************************************************************************************************************************/
/*  Name	    : Assign8_C_Program_To_Make_a_Simple_Calculator.c
 *  Created on  : Aug 22, 2023
 *  Author	    : Seifeldin Ahmed
 *  Description : Make a Simple Calculator ----> using(C89)
 */
/********************************************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int main()
{
	float operand1,operand2,result;
	char operator;

    printf("Enter operator either + or - or * or divide: ");
    fflush(stdout);  fflush(stdin);
    scanf("%c",&operator);

    printf("Enter two operands: ");
    fflush(stdout);  fflush(stdin);
    scanf("%f %f",&operand1,&operand2);

    switch(operator)
    {
    	case '+' : result = operand1 + operand2; break;
    	case '-' : result = operand1 - operand2; break;
    	case '*' : result = operand1 * operand2; break;
    	case '/' : result = operand1 / operand2; break;
    	default:
    		printf("wrong operator"); break;
    }
    printf("result = %0.2f %c %0.2f = %0.2f",operand1,operator,operand2,result);

    return 0;
}
