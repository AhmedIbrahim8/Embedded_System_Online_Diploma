/*
 ============================================================================
 Name        : EX_1_Prime_Number_between_interval.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void func(int num1,int num2){
    int number=num1+1;
    int flag=0;
    printf("Prime numbers between %d and %d are: ",num1,num2);
    fflush(0);
    for(;number<num2;number++){
        for(int i=2;i<number;i++){
            if(((float)number/i)==(number/i)){
                flag=1;
                break;
            }
            else{
                flag=0;
            }

        }
        if(flag==0){
            printf("%d ",number);
            fflush(0);
        }
        else{
            flag=0;
        }
    }

}

int main() {
    int num1,num2;
    printf("Enter two numbers(intervals) : ");
    fflush(0);
    scanf("%d%d",&num1,&num2);
    func(num1,num2);
   return 0;
}


