


#include "Std_Types.h"
#include "common_macros.h"

#define  RCC_BASE_ADDRESS              0x40021000
#define  PORTA_BASE_ADDRESS            0x40010800

#define  RCC_APB2ENR_OFFSET_ADDRESS    0x18
#define  PORTA_CRH_OFFSET_ADDRESS      0x04
#define  PORTA_ODR_OFFSET_ADDRESS      0x0C


#define  RCC_APB2ENR  *((volatile uint32 *)(RCC_BASE_ADDRESS+RCC_APB2ENR_OFFSET_ADDRESS))

#define  PORTA_CRH    *((volatile uint32 *)(PORTA_BASE_ADDRESS+PORTA_CRH_OFFSET_ADDRESS))

#define  PORTA_ODR    *((volatile uint32 *)(PORTA_BASE_ADDRESS+PORTA_ODR_OFFSET_ADDRESS))

volatile unsigned int *ptr=NULL_PTR;
unsigned char g_variables[5]={1,2,3};

unsigned char const const_variables[3]={1,2,3};

unsigned char bss_var[3];

int main(void)
{
	uint32 x;
	SET_BIT(RCC_APB2ENR,2);

	PORTA_CRH = (PORTA_CRH & 0xFF0FFFF) | (0x00200000);
    /* Loop forever */
	while(1){
		TOGGLE_BIT( PORTA_ODR,13);
		for( x=0;x<50000;x++);
	}

	return 0;
}
