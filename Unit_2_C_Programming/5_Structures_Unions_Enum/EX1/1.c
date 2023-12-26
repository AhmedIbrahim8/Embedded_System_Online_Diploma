#include<stdio.h>

typedef struct{
	char name[50];
	int roll;
	float marks;
}student;


int main(){
	student s;
	printf("Enter Student Name : ");
	gets(s.name);
	printf("Enter roll number : ");
	scanf("%d",&s.roll);
	printf("Enter mark : ");
	scanf("%f",&s.marks);
	
	printf("Diplaying \n");
	printf("Name : %s \n",s.name);
	printf("Roll : %d \n",s.roll);
	printf("Mark : %f \n",s.marks);
	return 0;
}