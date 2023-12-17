/*
 * LinkedList.h
 *
 *  Created on: Dec 16, 2023
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


//effective data
struct Sdata{
	int ID ;
	char name[40];
	float height ;
};

//linked list node
struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextStudent ;
};

#define DPRINTF(...) {fflush(stdout); \
                      fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
                      fflush(stdin); }

void LinkedList_AddStudent(struct SStudent ** head);

int LinkedList_DeleteStudent(struct SStudent ** head);

void LinkedList_ViewStudent(struct SStudent * head);

void LinkedList_DeleteAll(struct SStudent ** head);

struct Sdata * LinkedList_GetNode(struct SStudent * head);

int LinkedList_FindLength_IterativeMethod(struct SStudent * head);
int LinkedList_FindLength_RecursiveMethod(struct SStudent * head);

struct Sdata * LinkedList_GetNodeFromEnd(struct SStudent * head);

void LinkedList_FindMiddle(struct SStudent * head);

int LinkedList_DetectLoop(struct SStudent * head);

void LinkedList_ReverseList(struct SStudent ** head);



#endif /* LINKEDLIST_H_ */
