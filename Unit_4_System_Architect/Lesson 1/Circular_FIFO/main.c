/*******************************************************************************************/
/*  Module       :   main                                                                  */
/*  File Name    :   main.c                                                                */
/*  Description  :   Mini Application on Circular FIFO                                     */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/1/2024                                                             */
/*******************************************************************************************/


#include "fifo.h"

element_type uart_buff[WIDTH1];
int main(){

	FIFO_Buf_t FIFO_UART;

	element_type i,temp;

	if(FIFO_Init(&FIFO_UART,uart_buff,5) == FIFO_NO_ERROR){
		printf("FIFO Initialization ---- Done \n");
	}

	for(i=0;i<7;i++){
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_Enqueue(&FIFO_UART,i) == FIFO_NO_ERROR){
			printf("FIFO Enqueue    ---- Done \n");
		}
		else if(FIFO_Enqueue(&FIFO_UART,i) == FIFO_FULL){
			printf("FIFO Full       ---- Failed \n");
		}
		else if(FIFO_Enqueue(&FIFO_UART,i) == FIFO_NULL){
			printf("FIFO Not Exist  ---- Failed \n");
		}
	}

	FIFO_Print(&FIFO_UART);

	if(FIFO_Dequeue(&FIFO_UART,&temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue %x   ---- Done \n",temp);
	}

	if(FIFO_Dequeue(&FIFO_UART,&temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue %x   ---- Done \n",temp);
	}


	FIFO_Print(&FIFO_UART);

	return 0;
}
