#include<stdio.h>
int main(){
	float number;
	printf("Enter a number : ");
	fflush(0);
	scanf("%f",&number);
	if(number>0){
		printf("Number is positive ");
	}
	else if(number<0){
		printf("Number is negative ");
	}
	else{
		printf("Number is Zero ");
	}
	return 0;
}
