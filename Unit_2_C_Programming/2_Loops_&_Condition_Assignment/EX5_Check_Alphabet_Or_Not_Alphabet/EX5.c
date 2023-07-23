#include<stdio.h>

int main(){
	char ch;
	printf("Enter a character : ");
	fflush(0);
	scanf("%c",&ch);
	if((ch>='a' && ch<='b') || (ch>='A' && ch<= 'Z')){
		printf("%c is  Alphabet",ch);
	}
	else{
		printf("%c is not Alphabet",ch);
	}
	return 0;
}
