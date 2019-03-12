/*****************************************************************
Name    :myPow
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190312 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
double myPow(double x, int n) {

    if(0==n)
        return 1;

    double sqrt = myPow(x, n/2);

    if(n%2 == 0){
        return sqrt*sqrt;
    }else{
        if(n>0)
            return x*sqrt*sqrt;
        else
            return (sqrt*sqrt) / x;
    }

    return result;
}

/*==============================================================*/
int main(){
    double x=-2;
    int n=-3;

    double answer = myPow(x, n);
    printf("Answer is : %f\n", answer);

    return 0;
}
/*==============================================================*/