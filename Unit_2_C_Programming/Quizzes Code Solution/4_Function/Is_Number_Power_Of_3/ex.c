#include<stdio.h>
char Is_Power_Of_Three(int number){
	char boolean;
	if(number<=3){
		boolean=1;
	}
	else{
		while(1){
			/* Incase the number is not power of 3 */
			if( (number/3.0) - (number/3) >0){
				boolean =1;
				break;
			}
			else{
				number=number/3;
				if(number==1){
					boolean=0;
					break;
				}
			}
		}
	}
	return boolean;

}
int main(){
	while(1){
		int number;
		printf("Enter a number : ");
		scanf("%d",&number);
		char boolean=Is_Power_Of_Three(number);
		if(boolean==0){
			printf("Power of 3\n");
		}
		else{
			printf("Not power of three \n");
		}
	}
}