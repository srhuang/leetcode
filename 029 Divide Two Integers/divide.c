/*****************************************************************
Name    :divide
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190205 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor==-1)
        return INT_MAX;

    //handle sign
    int sign = ((dividend<0)^(divisor<0)) ? -1 : 1;
    long remainder=labs(dividend);
    long dvs=labs(divisor);
    long answer=0;
    printf("remainder: %ld\n", remainder);
    while(remainder >= dvs){
        //speed up 
        long multiple=1;
        long temp=dvs;
        while(remainder >= (temp<<1)){
            multiple <<= 1;
            temp <<= 1;
        }
        remainder -= temp;
        answer += multiple;
    }

    return sign==1 ? answer : -answer;
}

/*==============================================================*/
int main(){
    int dividend = -2147483648;
    int divisor = 1;

    int answer = divide(dividend, divisor);
    printf("Answer : %d\n", answer);

    return 0;
}
/*==============================================================*/