/*
 * main.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Seifeldin Ahmed Ismail
 */




#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "LinkedList.h"

struct SStudent * gpFirstStudent = NULL ;


int main()
{
	char temp_text[40];
	while(1)
	{
		DPRINTF("\n ===========================");
		DPRINTF("\n\t Choose one of the follwing Options \n");
		DPRINTF("\n\t 1: Add Student:  ");
		DPRINTF("\n\t 2: Delete Sudent:  ");
		DPRINTF("\n\t 3: view Sudent:  ");
		DPRINTF("\n\t 4: Delete All:  ");
		DPRINTF("\n\t 5: Get Node:  ");
		DPRINTF("\n\t 6: Find Length:  ");
		DPRINTF("\n\t 7: Get Node from the end:  ");
		DPRINTF("\n\t 8: Find Middle:  ");
		DPRINTF("\n\t 9: Detect Loop:  ");
		DPRINTF("\n\t 10: Reverse List:  ");

		DPRINTF("\n Enter Option Number: ");

		gets(temp_text);
		DPRINTF("\n ===========================");
		switch(atoi(temp_text))
		{
		case 1:
			LinkedList_AddStudent(&gpFirstStudent);
			break;
		case 2:
			LinkedList_DeleteStudent(&gpFirstStudent);
			break;
		case 3:
			LinkedList_ViewStudent(gpFirstStudent);
			break;
		case 4:
			LinkedList_DeleteAll(&gpFirstStudent);
			break;
		case 5:
			LinkedList_GetNode(gpFirstStudent);
			break;
		case 6:
			DPRINTF("\n The Length of List is: %d",LinkedList_FindLength_RecursiveMethod(gpFirstStudent));
			break;
		case 7:
			LinkedList_GetNodeFromEnd(gpFirstStudent);
			break;
		case 8:
			LinkedList_FindMiddle(gpFirstStudent);
			break;
		case 9:
			LinkedList_DetectLoop(gpFirstStudent);
			break;
		case 10:
			LinkedList_ReverseList(&gpFirstStudent);
			break;

		default:
			DPRINTF("\n wrong options");
			break;
		}
	}
	return 0;
}



