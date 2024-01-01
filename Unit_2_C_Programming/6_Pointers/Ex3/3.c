#include<stdio.h>



int main(){
	int i=0;
	char string[100];
	printf("Enter String  : ");
	gets(string);
	
	
	char *ptr=string;
	
	for(i=0;ptr[i]!='\0';i++){
		i++;
	}
	printf("The Reverse : ");
	for(i=i-1;i>=0;i--){
		printf("%c",ptr[i]);
	}
	
	return 0;
}