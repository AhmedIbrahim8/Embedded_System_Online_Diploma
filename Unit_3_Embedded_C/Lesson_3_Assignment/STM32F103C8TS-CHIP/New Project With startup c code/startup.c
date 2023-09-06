


#include "Std_Types.h"

extern int main();
void Reset_Handler(void);
void Default_Handler(){
	Reset_Handler();
}


void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Hard_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));

extern unsigned int _stack_top;

uint32 Vectors[] __attribute__((section(".vectors"))) ={
	(uint32)&_stack_top ,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&Hard_Fault_Handler,
	(uint32)&MM_Fault_Handler,
	(uint32)&Bus_Fault_Handler,
	(uint32)&Usage_Fault_Handler
	
};


extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;




void Reset_Handler(){
	/* Copy Data section from FLASH	 to SRAM*/
	unsigned int i;
	unsigned int DATA_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	
	unsigned char* P_src = (unsigned char *)&_E_text;
	
	unsigned char* P_dst = (unsigned char *)&_S_DATA;
	for(i=0;i<DATA_size;i++){
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}
	/* Initialize the BSS section */
	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	P_dst = (unsigned char *)&_S_bss;
	for(i=0;i<bss_size;i++){
		*((unsigned char *)P_dst++)=(unsigned char)0 ;
	}
	/* Call th main function */
	main();
}
