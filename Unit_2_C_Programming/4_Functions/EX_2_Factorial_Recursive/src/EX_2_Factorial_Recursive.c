/*
 ============================================================================
 Name        : EX_2_Factorial_Recursive.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
int factorial(int number);

int main(){
	int n;
	printf("Enter a positive number : ");
	fflush(0);
	scanf("%d",&n);
	printf("Factorial of %d = %d",n,factorial(n));
	return 0;
}
int factorial(int number){
	if(number<1){
		return 1;
	}
	else{
		return number*factorial(number-1);
	}
}
