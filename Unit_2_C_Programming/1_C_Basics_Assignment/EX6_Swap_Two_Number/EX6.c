#include<stdio.h>
void swap(float *,float *);

int main(){
	float a,b;
	printf("Enter value of a : ");
	fflush(0);
	scanf("%f",&a);
	printf("Enter value of b : ");
	fflush(0);
	scanf("%f",&b);
	swap(&a,&b);
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of a = %f",b);
	return 0;
}

void swap(float *a,float *b){
	float temp=*a;
	*a=*b;
	*b=temp;
}
