/*
 ============================================================================
 Name        : EX5_Search_on_element.c
 Author      : Ahmed Ibrahim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include<stdio.h>
int main(){
	int index;
	int size;
	int search;
	int number[10];
	printf("Enter no of Elements : ");
	fflush(0);
	scanf("%d",&size);
	for(index=0;index<size;index++){
		printf("Enter Number %d : ",index+1);
		fflush(0);
		scanf("%d",number+index);
	}
	printf("Enter a value to search about : ");
	fflush(0);
	scanf("%d",&search);
	for(index=0;index<size;index++){
		if(search == number[index]){
			printf("Number %d is found at location %d ",search,index+1);
		}
	}

	return 0;
}
