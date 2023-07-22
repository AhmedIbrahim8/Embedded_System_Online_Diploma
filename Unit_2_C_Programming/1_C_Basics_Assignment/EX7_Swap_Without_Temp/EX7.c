#include<stdio.h>


int main(){
	float a,b;
	printf("Enter value of a : ");
	fflush(0);
	scanf("%f",&a);
	printf("Enter value of b : ");
	fflush(0);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of a = %f",b);
	return 0;
}
