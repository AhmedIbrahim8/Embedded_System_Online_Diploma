#include<stdio.h>
int last_occurance(int arr [],int size){
	int get_key;
	printf("Enter the number you want to get its last occurrence : ");
	fflush(0);
	scanf("%d",&get_key);
	for(int index=size-1;index>=0;index--){
		if(arr[index]==get_key){
			return index+1;
		}
	}
	return -1;
}
int main(){
	int arr[100],size;
	printf("Enter size of array :");
	fflush(0);
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		printf("Enter element %d : ",i+1);
		fflush(0);
		scanf("%d",&arr[i]);
	}
	int last=last_occurance(arr,size);
	printf("Last occurence is %d",last);
	return 0;
}