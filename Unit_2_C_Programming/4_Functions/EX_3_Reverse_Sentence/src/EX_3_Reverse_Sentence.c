/*
 ============================================================================
 Name        : EX_3_Reverse_Sentence.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
void Reverse_sentence(char *string){
	int size=0;
	while(string[size]!='\0')
	{
		size++;
	}
	for(int index=size;index>=0;index--){
		printf("%c",string[index]);
	}
}

int main(void) {
	char string[1000];
	printf("Enter a sentence: ");
	fflush(0);
	gets(string);
	Reverse_sentence(string);
}
