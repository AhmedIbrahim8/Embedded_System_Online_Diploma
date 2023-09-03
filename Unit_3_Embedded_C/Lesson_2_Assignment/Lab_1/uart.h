#ifndef UART_H
#define UART_H

#define UART0_BASE_ADDRESS                    0x101F1000

#define UART0_DATA_REGISTER_OFFSET_ADDRESS    0x0

#define UART0DR   *((volatile unsigned int * const)(UART0_BASE_ADDRESS+UART0_DATA_REGISTER_OFFSET_ADDRESS))


void Uart_Send_string(unsigned char * P_tx_string);

#endif