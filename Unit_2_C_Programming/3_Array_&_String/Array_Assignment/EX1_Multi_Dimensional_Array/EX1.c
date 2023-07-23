#include<stdio.h>

int main(){
	float a[2][2];
	float b[2][2];
	float sum[2][2]={0};
	int index1,index2;
	printf("Enter the elements of 1st matrix \n");
	fflush(0);
	for(index1=0;index1<2;index1++){
		for(index2=0;index2<2;index2++){
			printf("Enter a%d%d : ",index1+1,index2+1);
			fflush(0);
			scanf("%f",&a[index1][index2]);
		}
	}
	printf("Enter the elements of 2st matrix \n");
	fflush(0);
	for(index1=0;index1<2;index1++){
		for(index2=0;index2<2;index2++){
			printf("Enter b%d%d : ",index1+1,index2+1);
			fflush(0);
			scanf("%f",&b[index1][index2]);
			/* sum of the 2-arrays*/
			sum[index1][index2]=a[index1][index2]+b[index1][index2];
		}
	}
	printf("Sum of matrix : \n");
	fflush(0);
	for(int index1;index1<2;index1++){
		for(index2=0;index2<2;index2++){
			printf("%f\t",sum[index1][index2]);
		}
		printf("\n");
	}
	return 0;
}
