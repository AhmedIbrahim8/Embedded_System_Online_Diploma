#include<stdio.h>
#include<stdlib.h>

#include"lifo.h"



unsigned int buffer1[5];



int main(){

	LIFO_Buf_t UART_lifo, I2C_lifo;

	/*  Static Allocation  */
	LIFI_Init(&UART_lifo,buffer1,5);

	unsigned int *buffer2 = (unsigned int *)malloc(sizeof(int)*5);
	/*  Dynamic Allocation */
	LIFI_Init(&I2C_lifo,buffer2,5);


	return 0;
}
