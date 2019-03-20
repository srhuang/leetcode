/*****************************************************************
Name    :mySqrt
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190320 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int mySqrt(int x) {
    if(0==x)
        return 0;
    long left = 1;
    long right = x;
    long mid;
    while(true){
        mid = (left + right)/2;
        if(mid > x/mid){ // too big
            right = mid-1;
        }else{ //smaller or equal
            if((mid+1) > x/(mid+1))
                break;
            left = mid+1;
        }
    }
    printf("result : %ld\n", mid);
    return mid;
}

/*==============================================================*/
int main(){

    int answer = mySqrt(10);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/