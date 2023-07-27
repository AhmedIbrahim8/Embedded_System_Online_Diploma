/*
 ============================================================================
 Name        : EX4_Insert_element_inside_array.c
 Author      : Ahmed Ibrahim
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array[100];
	int size;
	int data;
	int location;
	printf("Enter no of elements : ");
	fflush(0);
	scanf("%d",&size);
	for(int index=0;index<size;index++){
		scanf("%d",&array[index]);
	}
	printf("Enter the element to be inserted : ");
	fflush(0);
	scanf("%d",&data);
	printf("Enter the location : ");
	fflush(0);
	scanf("%d",&location);
	size=size+1;
	for(int index=size-1;index>location-1;index--){
		array[index]=array[index-1];
	}
	array[location-1]=data;
	for(int index=0;index<size;index++){
		printf("%d ",array[index]);
	}
	return 100;
}
