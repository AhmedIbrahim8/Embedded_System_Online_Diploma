#include "uart.h"

/* Funnction responsible for sending string */
void Uart_Send_string(unsigned char * P_tx_string)
{
	/* Loop till pointer value not equal Null character */
	while(*P_tx_string != '\0'){
		/* Assign character to the data register of the uart to be transmitted */
		/* This register is 32 bit so, we must make casting to unsigned int */
		UART0DR = (unsigned int)(*P_tx_string);
		/* Increment the pointer to the next character location */
		P_tx_string++;
	}
}
