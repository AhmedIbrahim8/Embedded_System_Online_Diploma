/*
 ============================================================================
 Name        : EX_2_Length_of_string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>


int main(void) {
	char string[100];
	int index=0;
	printf("Enter a string : ");
	fflush(0);
	gets(string);
	while(string[index]!='\0'){
		index++;
	}
	printf("Length of string : %d",index);
	return 10;
}
