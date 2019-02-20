/*****************************************************************
Name    :firstMissingPositive
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190220 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
void swap(int *arg1, int *arg2){
    int temp= *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

/*==============================================================*/
//Function area
int firstMissingPositive(int* nums, int numsSize) {
    for(int i=0; i<numsSize; i++){
        //handle the value of position i
        while(nums[i]>0 && nums[i]<=numsSize && (nums[nums[i]-1] != nums[i])){//1~numsSize
            //printf("swap\n");
            swap(&nums[nums[i]-1], &nums[i]);
        }
    }

    //check the checking result
    /*
    printf("Result : ");
    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    */

    //check the first missing positive
    for(int i=0; i<numsSize; i++){
        if(nums[i] != i+1)
            return i+1;
    }
    return numsSize+1;
}

/*==============================================================*/
int main(){
    int test[]={1,2,0};
    int numsSize = sizeof(test)/sizeof(int);

    int answer = firstMissingPositive(test, numsSize);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/