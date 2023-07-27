/*
 ============================================================================
 Name        : EX_3.c
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
	index=index-1;
	printf("Reverse String is: ");
	for(;index>=0;index--){
		printf("%c",string[index]);
	}
	return 10;
}
