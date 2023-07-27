#include<stdio.h>

int main(){
	float array[1000]={0};
	float sum=0;
	int size;
	printf("Enter the number of data : ");
	fflush(0);
	scanf("%d",&size);
	for(int index=0;index<size;index++){
		printf("Enter number : ");
		fflush(0);
		scanf("%f",array+index);
		sum=sum+array[index];
	}
	printf("Average = %f",sum/size);
	return 100;
}
