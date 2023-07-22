#include<stdio.h>

int main(){
	char ch;
	printf("Enter a character : ");
	fflush(0);
	scanf("%c",&ch);
	printf("ASCII value of %c = %d",ch,ch);
}
