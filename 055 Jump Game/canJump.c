/*****************************************************************
Name    :canJump
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190313 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

/*==============================================================*/
//Function area
bool canJump(int* nums, int numsSize) {
    int end=0;
    int max=0;

    for(int i=0; i<numsSize; i++){
        max = MAX(max, i+nums[i]);
        if(i == end){
            end = max;
        }
    }

    if(end >= numsSize-1)
        return true;
    else
        return false;
}

/*==============================================================*/
int main(){
    //int test_data[] = {2,3,1,1,4};
    int test_data[] = {3,2,1,0,4};

    bool answer = canJump(test_data, sizeof(test_data)/sizeof(int));
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/