/*
 * lifo.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Ahmed
 */

#ifndef LIFO_H_
#define LIFO_H_

/* Type Definitions*/
typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int *head;
}LIFO_Buf_t;


typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_Status;

/* APIs Prototypes */

LIFO_Status LIFI_Add_Item(LIFO_Buf_t *lifo_buf,unsigned int item);

LIFO_Status LIFI_Get_Item(LIFO_Buf_t *lifo_buf,unsigned int* item);

LIFO_Status LIFI_Init(LIFO_Buf_t *lifo_buf,unsigned int *buf,unsigned int length);



#endif /* LIFO_H_ */
