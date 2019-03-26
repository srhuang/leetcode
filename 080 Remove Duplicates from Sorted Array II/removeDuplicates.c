/*****************************************************************
Name    :removeDuplicates
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190326 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int removeDuplicates(int* nums, int numsSize) {
    int eliminate=0;
    for(int i=2; i<numsSize; i++){
        if(nums[i] == nums[i-eliminate-2]){
            eliminate++;
        }else{
            nums[i-eliminate] = nums[i];
        }
    }//for

    return numsSize-eliminate;
}

/*==============================================================*/
int main(){
    int test[] = {0,0,1,1,1,1,2,3,3};
    int size = sizeof(test)/sizeof(int);

    int answer = removeDuplicates(test, size);
    printf("Answer is %d\n", answer);
    for(int i=0; i<answer; i++){
        printf(" %d", test[i]);
    }

    return 0;
}
/*==============================================================*/