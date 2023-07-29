/*
 ============================================================================
 Name        : EX_4_Power_Of_A_Given_Number.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
unsigned int PowerNumber (unsigned int number ,unsigned int  power);

int main(void) {
	int number ;
	unsigned int  power;
	printf("Enter any number: ");
	fflush(0);
	scanf("%d",&number);
	printf("Enter power number: ");
	fflush(0);
	scanf("%d",& power);
	printf("%d ^ %d = %d",number , power ,PowerNumber(number ,  power));
}

unsigned int PowerNumber (unsigned int number ,unsigned int power)
{

	if( power != 1)
		return number *PowerNumber(number , power-1) ;
	else
		return number;
}
