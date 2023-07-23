#include<stdio.h>

int main(){
	int number;
	int counter;
	unsigned int fact=1;
	printf("Enter an integer : ");
	fflush(0);
	scanf("%d",&number);
	if(number<0){
		printf("Error!!! Factorial of negative number does not exist");
	}
	else{
		for(counter=1;counter<=number;counter++){
			fact=fact*counter;
		}
		printf("Factorial of %d is %u",number,fact);
	}

	return 0;
}
