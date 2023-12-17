/*
 * LinkedList.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Seifeldin Ahmed Ismail
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "LinkedList.h"



void LinkedList_AddStudent(struct SStudent ** head)
{
	char temp_text[40];
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	//check list is empty == yes
	if(*head == NULL)
	{
		//create new record
		pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		*head = pNewStudent ;
	}
	else{ //no , list contains records
		//navigate until reach to the last record
		pLastStudent = *head ;
		while(pLastStudent->PNextStudent != NULL)
			pLastStudent = pLastStudent->PNextStudent;
		pNewStudent =  (struct SStudent*) malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent ;
	}
	// fill new record
	DPRINTF("\n Enter the ID: ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	DPRINTF("\n Enter student full name: ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter the height: ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);

	//set the next pointer (new_student)null
	pNewStudent->PNextStudent = NULL;
}

int LinkedList_DeleteStudent(struct SStudent ** head)
{
	char temp_text[40] ;
	unsigned int selected_id ;
	//get the selected id
	DPRINTF("\n enter the student id to be deleted: ");
	gets(temp_text);
	selected_id = atoi (temp_text);

	//list is not empty
	if(*head)
	{
		struct SStudent* pSelectedStudent = *head;
		struct SStudent* pPreviousStudent = NULL;
		while(pSelectedStudent) //while pSelectedStudent is exist
		{
			//compare each node with the selected ID
			if(pSelectedStudent->student.ID == selected_id)
			{
				if(pPreviousStudent) // the first student is not the selected one
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
				}
				else{ //1st student == ID
					*head = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			else
			{
				pPreviousStudent = pSelectedStudent;
				pSelectedStudent = pSelectedStudent->PNextStudent;
			}
		}
		DPRINTF("\n cannot find student ID \n");
		return 0;
	}
	DPRINTF("\n list is empty \n");
	return -1;
}

void LinkedList_ViewStudent(struct SStudent * head)
{
	struct SStudent* pCurrentStudent = head;
	int count = 1;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n\n record number %d",count);
			DPRINTF("\n \t ID: %d",pCurrentStudent->student.ID);
			DPRINTF("\n \t name: %s",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %0.3f",pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			count++;
		}
	}
}

void LinkedList_DeleteAll(struct SStudent ** head)
{
	struct SStudent* pCurrentStudent = *head;
	if(*head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		*head = NULL;
		DPRINTF("\n All Elements has been Deleted");
	}
}

struct Sdata * LinkedList_GetNode(struct SStudent * head)
{
	char temp_text[40] ;
	unsigned int index ;
	//get the selected index
	DPRINTF("\n enter the student index: ");
	gets(temp_text);
	index = atoi (temp_text);

	struct SStudent* pCurrentStudent = head;
	unsigned int count = 0;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			if(index==count)
			{
				DPRINTF("\n Student Information are: ");
				DPRINTF("\n \t ID: %d",pCurrentStudent->student.ID);
				DPRINTF("\n \t name: %s",pCurrentStudent->student.name);
				DPRINTF("\n \t height: %0.3f",pCurrentStudent->student.height);
				return &(pCurrentStudent->student);
			}
			else
			{
				count++;
				pCurrentStudent = pCurrentStudent->PNextStudent;
			}
		}
		DPRINTF("\n Element is not in the list\n");
	}
	return NULL;
}

int LinkedList_FindLength_IterativeMethod(struct SStudent * head)
{
	struct SStudent* pCurrentStudent = head;
	unsigned int count = 0;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrentStudent)
		{
			count++;
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	}
	return count;
}

int LinkedList_FindLength_RecursiveMethod(struct SStudent * head)
{
	if(head == NULL)
	{
		return 0;
	}
	return 1 + LinkedList_FindLength_RecursiveMethod(head->PNextStudent);
}

struct Sdata * LinkedList_GetNodeFromEnd(struct SStudent * head)
{
	char temp_text[40] ;
	unsigned int n ;
	DPRINTF("\n enter the node number: ");
	gets(temp_text);
	n = atoi (temp_text);

	struct SStudent* prefStudent  = head;
	struct SStudent* pmainStudent = head;
	unsigned int count = 0;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(prefStudent)
		{
			prefStudent = prefStudent->PNextStudent ;
			count++;
			if(count>n)
			{
				pmainStudent = pmainStudent->PNextStudent ;
			}
		}
		if(count>=n)
		{
			DPRINTF("\n Student Information are: ");
			DPRINTF("\n \t ID: %d",pmainStudent->student.ID);
			DPRINTF("\n \t name: %s",pmainStudent->student.name);
			DPRINTF("\n \t height: %0.3f",pmainStudent->student.height);
			return &pmainStudent->student;
		}
	}
	DPRINTF("\n Element is not in the list\n");
	return NULL;
}

void LinkedList_FindMiddle(struct SStudent * head)
{
	struct SStudent* pSlow  = head;
	struct SStudent* pFast= head;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pFast && pFast->PNextStudent)
		{
			pFast = pFast->PNextStudent->PNextStudent;
			pSlow = pSlow->PNextStudent;
		}
		DPRINTF("\n The information of the Middle element are:");
		DPRINTF("\n \t ID: %d",pSlow->student.ID);
		DPRINTF("\n \t name: %s",pSlow->student.name);
		DPRINTF("\n \t height: %0.3f",pSlow->student.height);
	}
}

int LinkedList_DetectLoop(struct SStudent * head)
{
	struct SStudent* pSlow  = head;
	struct SStudent* pFast= head;
	if(head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pFast && pFast->PNextStudent)
		{
			pFast = pFast->PNextStudent->PNextStudent;
			pSlow = pSlow->PNextStudent;
			if(pFast == pSlow)
			{
				DPRINTF("\n Loop Detected");
				return 1;
			}
		}
	}
	DPRINTF("\n No Loop Detected");
	return 0;
}

void LinkedList_ReverseList(struct SStudent ** head)
{
	struct SStudent* pPrev    = *head;
	struct SStudent* pCurrent = *head;
	struct SStudent* pNext    = *head;
	if(*head == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while(pCurrent)
		{
			pNext = pCurrent->PNextStudent;
			pCurrent->PNextStudent = pPrev;
			pPrev = pCurrent ;
			pCurrent =pNext  ;
		}
		(*head)->PNextStudent = NULL;
		*head = pPrev;
	}
	DPRINTF("\n List is successfully reversed ");
}
