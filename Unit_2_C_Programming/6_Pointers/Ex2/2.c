#include<stdio.h>



int main(){
	
	char ch[27];
	int i=0;
	char *ptr=ch;
	for(i=0;i<26;i++){
		ptr[i]=i+'A';
	}
	printf("The Alphabets : ");
	for(i=0;i<26;i++){
		printf("%c ",ptr[i]);
	}
	
	return 0;
}