/*******************************************************************************************/
/*  Module       :   FIFO                                                                  */
/*  File Name    :   fifo.h                                                                */
/*  Description  :   Header File of Circular FIFO Algorithm                                */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/1/2024                                                             */
/*******************************************************************************************/

#ifndef FIFO_H_
#define FIFO_H_

#include<stdio.h>
#include<stdint.h>


/*       User Configuration
 *  Select the element type (uint8_t , uint26_t , uint32_t , ... )
 *  Select the width of the Buffer
 * */
#define    element_type     uint8_t
#define    WIDTH1              5



/* FIFO DATA TYPES */
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type * base;
	element_type * tail;
	element_type * head;
}FIFO_Buf_t;


typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_Buf_Status;




/* APIs Prototypes */
FIFO_Buf_Status   FIFO_Init(FIFO_Buf_t *fifo,element_type *buf,unsigned int length);

FIFO_Buf_Status   FIFO_Enqueue(FIFO_Buf_t *fifo,element_type item );

FIFO_Buf_Status   FIFO_Dequeue(FIFO_Buf_t *fifo,element_type* item );

FIFO_Buf_Status   FIFO_IS_FULL(FIFO_Buf_t *fifo);

void              FIFO_Print(FIFO_Buf_t *fifo);

#endif /* FIFO_H_ */
