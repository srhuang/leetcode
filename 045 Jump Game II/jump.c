/*****************************************************************
Name    :jump
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190225 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MAX(a,b) (((a)>(b))?(a):(b))

/*==============================================================*/
//Function area
int jump(int* nums, int numsSize) {
    int end=0;
    int steps=0;
    int max=0;

    for(int i=0; i<numsSize-1; i++){
        max = MAX(max, nums[i]+i);
        if(i == end){
            end = max;
            steps++;
        }
    }

    return steps;
}

/*==============================================================*/
int main(){
    int test_data[] = {2,3,1,1,4};
    int size = sizeof(test_data)/sizeof(int);

    int answer = jump(test_data, size);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/