/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"

#include "core_cm4.h"

unsigned char flag;

void OS_SVC_services (int *StackFramePointer)
{
	unsigned char SVC_number;

	/* StackFramePointer[0] => R0  */
	/* StackFramePointer[1] => R1  */
	/* StackFramePointer[2] => R2  */
	/* StackFramePointer[3] => R3  */
	/* StackFramePointer[4] => R12 */
	/* StackFramePointer[5] => LR  */
	/* StackFramePointer[6] => PC  */
	unsigned int stacked_r0=StackFramePointer[0];
	unsigned int stacked_r1=StackFramePointer[1];
	SVC_number = *((unsigned char *)(((unsigned char *)StackFramePointer[6])[-2]));

	switch(SVC_number)
	{
	case 1:
		StackFramePointer[0] = stacked_r0 + stacked_r1;
		break;
	case 2:
		StackFramePointer[0] = stacked_r0 - stacked_r1;
		break;
	case 3:
		StackFramePointer[0] = stacked_r0 * stacked_r1;
		break;
	}
}



__attribute ((naked)) void SVC_Handler()
{
	/* Check the execution code return */
	__asm("tst lr, #4 \n\t"
		   "ITE EQ \n\t"
		   "mrseq r0,MSP \n\t"
		   "mrsne r0,PSP \n\t"
		   "b OS_SVC_services");
}





int OS_SVC_Set(int a,int b,int SVC_ID)
{
	int result;
	switch(SVC_ID)
	{
	/* ADD */
	case 1:
		__asm ("SVC #0x01");
		break;
	/* SUB */
	case 2:
		__asm ("SVC #0x02");
		break;
	/* MULT */
	case 3:
		__asm ("SVC #0x03");
		break;



	}



	return result;
}







int main (){

	flag=1;
	flag = OS_SVC_Set(3,3,1);
	flag = OS_SVC_Set(3,3,2);
	flag = OS_SVC_Set(3,3,3);

	return 0;
}
