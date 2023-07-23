#include<stdio.h>

int main(){
	float number1,number2,number3;
	printf("Enter Three Numbers : ");
	fflush(0);
	scanf("%f%f%f",&number1,&number2,&number3);
	if(number1>number2){
		if(number1>number3){
			printf("%f is the largest \n",number1);
		}
		else{
			printf("%f is the largest \n",number3);
		}
	}
	else{
		if(number2>number3){
			printf("%f is the largest \n",number2);
		}
		else{
			printf("%f is the largest \n",number3);
		}
	}

}
