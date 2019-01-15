/*****************************************************************
Name    :ReverseInteger
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190115 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 

/*==============================================================*/
int reverse(int x) {
    int divide=x;
    int answer=0;
    while(0!=divide){
        if(answer>0 && answer>INT_MAX/10) return 0;
        answer *= 10;

        if(answer > 0 && answer>INT_MAX-divide%10) return 0;
        answer+=divide%10;
        divide /= 10;
        printf("answer=%d, divide=%d\n", answer, divide);
    }

    return answer;
}

/*==============================================================*/
int main(){
    int test_data=-321;
    //char test_data[1000]="abcde";
    int answer=reverse(test_data);
    printf("Answer is %d\n", answer);

    return 0;
}