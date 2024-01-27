/*******************************************************************************************/
/*  Module       :   FIFO                                                                  */
/*  File Name    :   fifo.c                                                                */
/*  Description  :   Source File of Circular FIFO Algorithm                                */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/1/2024                                                             */
/*******************************************************************************************/

#include"fifo.h"

/* APIs Prototypes */
FIFO_Buf_Status   FIFO_Init(FIFO_Buf_t *fifo,element_type *buf,unsigned int length){
	/* Incase the fifo buffer is null */
	if(buf == NULL){
		return FIFO_NULL;
	}
	/* The Three pointer at first points to the base of the buffer
	 * The length of the fifo should be the length of the buffer
	 * the count in the fifo is initialized to zero
	 * */
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_NO_ERROR;
}

FIFO_Buf_Status   FIFO_Enqueue(FIFO_Buf_t *fifo,element_type item ){

	/* Check if the FIFO is null */
	if(fifo->base== NULL || fifo->tail== NULL  || fifo->head== NULL){
		return FIFO_NULL;
	}
	/* Check if FIFO is Full */
	if(FIFO_IS_FULL(fifo) == FIFO_FULL){
		return FIFO_FULL;
	}

	/* The addition takes place in the head pointer */
	*(fifo->head) = item;
	fifo->count++;

	/* Circular FIFO Algorithm */
	/* Here, we want to check if the head reach the top of the buffer or not */
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type) ))){
		fifo->head = fifo->base;
	}
	else{
		fifo->head++;
	}


	return FIFO_NO_ERROR;
}

FIFO_Buf_Status   FIFO_Dequeue(FIFO_Buf_t *fifo,element_type* item ){
	/* Check if the FIFO is null */
	if(fifo->base== NULL || fifo->tail== NULL  || fifo->head== NULL){
		return FIFO_NULL;
	}
	/* Check if FIFO is Empty */
	if(fifo->count ==0){
		return FIFO_EMPTY;
	}

	/* the first out is at the tail */
	*item = *(fifo->tail);

	fifo->count--;

	/* Circular FIFO Algorithm */
	/* Here, we want to check if the head reach the tail of the buffer or not */
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type) ))){
		fifo->tail = fifo->base;
	}
	else{
		fifo->tail++;
	}


	return FIFO_NO_ERROR;
}

FIFO_Buf_Status   FIFO_IS_FULL(FIFO_Buf_t *fifo){

	/* Check if the FIFO is null */
	if(fifo->base== NULL || fifo->tail== NULL  || fifo->head== NULL){
		return FIFO_NULL;
	}

	if(fifo->count == fifo->length){
		return FIFO_FULL;
	}


	return FIFO_NO_ERROR;
}


void              FIFO_Print(FIFO_Buf_t *fifo){
	element_type *temp;
	int i=0;
	if(fifo->count ==0){
		printf("Fifo is Empty \n");
	}
	else{
		temp = fifo->tail;
		printf("\n =============== FIFO Print ===========\n");
		for(i=0;i<fifo->count;i++){
			printf("\t %X  \n",*temp);
			temp++;
		}
		printf("==================\n");
	}


}
