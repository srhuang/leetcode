/*****************************************************************
Name    :climbStairs
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
int climbStairs(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    int *fib = malloc(sizeof(int)*n);
    fib[0] = 1;
    fib[1] = 2;
    for(int i=2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    int result = fib[n-1];
    free(fib);
    fib=NULL;
    return result;
}

/*==============================================================*/
int main(){

    int answer = climbStairs(5);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/