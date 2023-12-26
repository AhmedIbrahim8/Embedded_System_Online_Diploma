#include<stdio.h>



typedef struct{
	char name[50];
	int roll;
	float mark;
}student;



int main(){
	
	student s[10];
	for(int i=0;i<10;i++){
		printf("Enter student %d data \n",i+1);
		printf("Enter Name: ");
		gets(s[i].name);
		printf("Enter Roll: ");
		scanf("%d",&s[i].roll);
		printf("Enter Mark: ");
		scanf("%f",&s[i].mark);
		printf("----------------------------------------------\n");
	}
	for(int i=0;i<10;i++){
		printf("Student %d data \n",i+1);
		printf("Name = %s \n",s[i].name);
		printf("Roll = %d \n",s[i].roll);
		printf("Mark = %0.2f \n",s[i].mark);
	}
	
	
	
	return 0;
}