/*****************************************************************
Name    :singleNumber
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190923 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area

int singleNumber(int* nums, int numsSize){
    int answer=0;
    for(int i=0; i<numsSize; i++){
        answer ^= nums[i];
    }

    return answer;
}

/*==============================================================*/
int main(){
    int test[7] = {4,1,2,1,2,4,6};
    int size = sizeof(test)/sizeof(int);

    int answer = singleNumber(test, size);
    printf("answer : %d\n", answer);

    return 0;
}
/*==============================================================*/