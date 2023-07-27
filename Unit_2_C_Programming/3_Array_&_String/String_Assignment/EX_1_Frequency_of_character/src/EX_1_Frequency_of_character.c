/*
 ============================================================================
 Name        : EX_1_Frequency_of_character.c
 Author      : 
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>


int main(void) {
	char string[100];
	char ch;
	int counter=0;
	int index=0;
	printf("Enter a string : ");
	fflush(0);
	gets(string);
	printf("Enter a character to find frequency: ");
	fflush(0);
	scanf("%c",&ch);
	while(string[index]!='\0'){
		if(string[index]==ch){
			counter++;
		}
		index++;
	}
	printf("Frequency of %c = %d",ch,counter);
	return 1000;
}
