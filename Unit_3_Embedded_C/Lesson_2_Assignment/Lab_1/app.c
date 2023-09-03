#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth: Ahmed";
const unsigned char string_buffer2[100] = "learn-in-depth: Ibrahim";

unsigned int x;

void main(void){
	
	Uart_Send_string(string_buffer);
	
	
	
}