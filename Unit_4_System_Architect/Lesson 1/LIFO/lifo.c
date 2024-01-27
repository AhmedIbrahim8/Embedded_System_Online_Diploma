/*
 * lifo.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Ahmed
 */


#include "lifo.h"

#define  NULL  (void *)0
/* APIs Definitions */

LIFO_Status LIFI_Add_Item(LIFO_Buf_t *lifo_buf,unsigned int item)
{
	/* Check the LIFO is exist or not */
	if( (lifo_buf->base == NULL) || (lifo_buf->head == NULL) ){
		return LIFO_NULL;
	}
	/* Check if the LIFO is Full or not */
	else if(lifo_buf-> length == lifo_buf->count){
		return LIFO_FULL;
	}
	else{
		*(lifo_buf->head) = item;

		lifo_buf->count++;

		lifo_buf->head++;

		return LIFO_NO_ERROR;
	}
}



LIFO_Status LIFI_Get_Item(LIFO_Buf_t *lifo_buf,unsigned int* item){
	/* Check the LIFO is exist or not */
	if( (lifo_buf->base == NULL) || (lifo_buf->head == NULL) ){
		return LIFO_NULL;
	}
	/* Check if the LIFO is Full or not */
	else if(lifo_buf-> count == 0){
		return LIFO_EMPTY;
	}
	else{
		lifo_buf->head--;

		*item =*(lifo_buf->head);

		lifo_buf->count--;

		return LIFO_NO_ERROR;
	}

}



LIFO_Status LIFI_Init(LIFO_Buf_t *lifo_buf,unsigned int *buf,unsigned int length){

	if(buf == NULL){
		return LIFO_NULL;
	}

	/* Initialize the LIFO with the buffer */
	lifo_buf->base = buf;

	lifo_buf->head = buf;

	lifo_buf->length = length;

	lifo_buf->count = 0;

	return LIFO_NO_ERROR;

}
