/*
 ============================================================================
 Name        : EX3_Transpose_of_matric.c
 Author      : Ahmed Ibrahim
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int array[100][100];
	int row,col;
	printf("Enter rows and column of matrix: ");
	fflush(0);
	scanf("%d%d",&row,&col);
	printf("Enter elements of matrix:\n");
	for(int index1=0;index1<row;index1++){
		for(int index2=0;index2<col;index2++){
			printf("Enter elements a%d%d: ",index1+1,index2+1);
			fflush(0);
			scanf("%d",&array[index1][index2]);
		}
	}
	printf("Entered Matrix:\n");
	for(int index1=0;index1<row;index1++){
		for(int index2=0;index2<col;index2++){
			printf("%d\t",array[index1][index2]);
			fflush(0);
		}
		printf("\n");
	}
	printf("Transpose of Matrix:\n");
	for(int index1=0;index1<col;index1++){
		for(int index2=0;index2<row;index2++){
			printf("%d\t",array[index2][index1]);
			fflush(0);
		}
		printf("\n");
	}
	return 100;
}
