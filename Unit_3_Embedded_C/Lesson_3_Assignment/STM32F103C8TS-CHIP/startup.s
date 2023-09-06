/********************************************************/
/*                Startup.s for Coretex M3              */
/* Name : Ahmed Ibrahim                                 */
/* Date : 05/09/2023                                    */
/********************************************************/

.section .vectors
.word   0x20001000
.word   _reset          /* 1 Reset handler Address        */
.word   Vector_handler  /* 2 NMI Handler                  */
.word   Vector_handler  /* 3 Hard Fault Handler           */
.word   Vector_handler  /* 4 Memory Management Handler    */
.word   Vector_handler  /* 5 Bus Fault Handler            */
.word   Vector_handler  /* 6 Usage Fault Handler          */
.word   Vector_handler  /* 7 Reserved           */
.word   Vector_handler  /* 8 Reserved           */
.word   Vector_handler  /* 9 Reserved           */
.word   Vector_handler  /* 10 Reserved           */
.word   Vector_handler  /* 11 SVCall Handler           */
.word   Vector_handler  /* 12 Debug Monitor Handler    */
.word   Vector_handler  /* 13 reserved           */
.word   Vector_handler  /* 14 PendSV Handler           */
.word   Vector_handler  /* 15 SysTick Handler          */
.word   Vector_handler  /* 16 IRQ0          */
.word   Vector_handler  /* 17 IRQ1         */
.word   Vector_handler  /* 18 IRQ2         */
.word   Vector_handler  /* 19... AND SO ON         */

.section .text
_reset:
	bl main
	b .
	
.thumb_func
Vector_handler:
	b _reset