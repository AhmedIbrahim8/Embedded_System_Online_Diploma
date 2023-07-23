#include<stdio.h>

int main(){
	unsigned int num;
	int counter;
	unsigned int sum=0;
	printf("Enter an integer : ");
	fflush(0);
	scanf("%u",&num);
	for(counter=1;counter<=100;counter++){
		sum=sum+counter;
	}
	printf("Sum = %u",sum);
	return 0;
}
