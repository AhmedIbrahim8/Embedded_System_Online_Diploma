#include<stdio.h>


#define     AREA_CIRCLE(R)                (3.14*(R)*(R))

int main(){
	float r;
	float area;
	printf("Enter the raduis : ");
	scanf("%f",&r);
	area = AREA_CIRCLE(r);
	printf("The Area = %0.3f",area);
	return 0;
}