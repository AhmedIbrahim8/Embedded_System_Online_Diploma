#include<stdio.h>
char Fourth_Bit(int number);
int main(){
	int number;
	printf("Enter a Number : ");
	scanf("%d",&number);
	printf("The Fourth Bit = %d",Fourth_Bit(number));
	return 0;
}

char Fourth_Bit(int number){
	return ((number&(1<<3))>>3);
}