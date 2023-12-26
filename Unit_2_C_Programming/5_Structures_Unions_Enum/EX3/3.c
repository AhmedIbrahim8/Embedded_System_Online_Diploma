#include<stdio.h>



typedef struct{
	float real;
	float imaj;
}complex;


void add(complex *n1,complex *n2){
	printf("Sum = %0.2f+%0.2fi",n1->real + n2->real,n1->imaj + n2->imaj);
	
}

int main(){
	
	complex n1,n2;
	printf("Enter Number 1 : ");
	scanf("%f %f",&n1.real,&n1.imaj);
	
	printf("Enter Number 2 : ");
	scanf("%f %f",&n2.real,&n2.imaj);
	
	add(&n1,&n2);
	
	return 0;
}