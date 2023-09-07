


#include "Std_Types.h"
#include "common_macros.h"

#define  SYSCTL_BASE_ADDRESS              0x400FE000
#define  SYSCTL_RCGC2_OFFSET_ADDRESS      0x108

#define  GPIOF_BASE_ADDRESS               0x40025000
#define  GPIOF_PORTF_DIR_OFFSET_ADDRESS   0x400
#define  GPIOF_PORTF_DATA_OFFSET_ADDRESS  0x3FC
#define  GPIOF_PORTF_DEN_OFFSET_ADDRESS   0x51C



#define  SYSCTL_RCGC2_R    *((volatile uint32 *)(SYSCTL_BASE_ADDRESS+SYSCTL_RCGC2_OFFSET_ADDRESS))

#define  GPIO_PORTF_DIR_R  *((volatile uint32 *)(GPIOF_BASE_ADDRESS+GPIOF_PORTF_DIR_OFFSET_ADDRESS))

#define  GPIO_PORTF_DEN_R  *((volatile uint32 *)(GPIOF_BASE_ADDRESS+GPIOF_PORTF_DEN_OFFSET_ADDRESS))

#define  GPIO_PORTF_DATA_R *((volatile uint32 *)(GPIOF_BASE_ADDRESS+GPIOF_PORTF_DATA_OFFSET_ADDRESS))




int main(void)
{
	volatile uint32 delay_count;
	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIOF is up and running
	for(delay_count=0;delay_count<200;delay_count++);
	/* Make pin 3 is output */
	GPIO_PORTF_DIR_R |= 1<<3;
	/* Enable digital */
	GPIO_PORTF_DEN_R |=1<<3;
	
    /* Loop forever */
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count=0;delay_count<200000;delay_count++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(delay_count=0;delay_count<200000;delay_count++);
		
	}

	return 0;
}
