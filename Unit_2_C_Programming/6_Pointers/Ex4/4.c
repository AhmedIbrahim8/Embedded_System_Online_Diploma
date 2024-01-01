#include<stdio.h>



int main(){
	int size=0;
	int number[15];
	printf("Input the number of elements to store in the array (max 15) : ");
	scanf("%d",&size);
	printf("Input %d number of elements in the array :\n",size);
	for(int i=0;i<size;i++){
		printf("element - %d: ",i+1);
		scanf("%d",number+i);
	}
	printf("The elements of array in reverse order are : \n"); 
	
	int *ptr=number;
	for(int i=size-1;i>=0;i--){
		printf("element - %d: %d\n",i+1,*(ptr+i));
	}
	
	
	return 0;
}