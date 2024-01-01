#include<stdio.h>

struct employee{
	char *empname;
	int empid;
};

int main(){
	struct employee emp1={"Alex",1002},emp2={"Ahmed",1003},emp3={"Nicole",1004};
	struct employee *array[]={&emp1,&emp2,&emp3};
	struct employee *(*ptr)[3]=&array;
	
	printf("Employee 1 : \n");
	printf("Name : %s \n",(**ptr)->empname);
	printf("ID   : %d ",(**ptr)->empid);
	
	
	
	return 0;
}