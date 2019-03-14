/*****************************************************************
Name    :uniquePaths
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int uniquePaths(int m, int n) {
    int larger = m>n?m:n;
    int smaller = m<=n?m:n;
    printf("larger is %d, smaller is %d\n", larger, smaller);
    int total = (m-1)+(n-1);
    long result = 1;
    for(int i=total; i>0; i--){
        if(i<=(larger-1))
            break;
        result *= i;
    }
    printf("result : %ld\n", result);

    for(int i=smaller-1; i>0; i--){
        result /= i;
    }

    return result;
}

/*==============================================================*/
int main(){

    int answer = uniquePaths(10,10);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/