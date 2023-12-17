/*
 * LIFO.h
 *
 *  Created on: Dec 15, 2023
 *      Author: Seifeldin Ahmed Ismail
 */

#ifndef LIFO_H_
#define LIFO_H_

// type definitions
typedef struct{
	unsigned int length ;
	unsigned int count  ;
	unsigned int* base  ;
	unsigned int* head  ;

}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null // this LIFO in not exist
}LIFO_status;


//APIs
LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf ,unsigned int* buf, unsigned int length);
LIFO_status LIFO_Add_item(LIFO_Buf_t * lifo_buf, unsigned int item);
LIFO_status LIFO_get_item(LIFO_Buf_t * lifo_buf, unsigned int* item);

#endif /* LIFO_H_ */
