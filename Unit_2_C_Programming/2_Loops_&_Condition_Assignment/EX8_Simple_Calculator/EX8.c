#include<stdio.h>

int main(){
	char ch;
	float num1,num2;
	printf("Enter operator either + or - or * or divide : ");
	fflush(0);
	scanf("%c",&ch);
	printf("Enter two operands : ");
	fflush(0);
	scanf("%f%f",&num1,&num2);
	switch(ch){
	case '+':
		printf("%f + %f = %f",num1,num2,num1+num2);
		break;
	case '-':
		printf("%f - %f = %f",num1,num2,num1-num2);
		break;
	case '*':
		printf("%f x %f = %f",num1,num2,num1*num2);
		break;
	case '/':
		printf("%f / %f = %f",num1,num2,num1/num2);
		break;
	default:
		printf("%c is not valid operator",ch);

	}
}
