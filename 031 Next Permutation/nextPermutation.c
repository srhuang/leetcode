/*****************************************************************
Name    :nextPermutation
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190205 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
void nextPermutation(int* nums, int numsSize){
    if(1 == numsSize)
        return;

    //anchor
    int pre = nums[numsSize-1];
    int current;
    int i;
    for(i=numsSize-2; i>=0; i--){
        current = nums[i];
        if(current < pre)
            break;
        else
            pre=current;
    }
    printf("nums[%d]=%d\n", i, current);

    //swap
    int j;
    for(j=numsSize-1; j>i; j--){
        if(nums[j] > current)
            break;
    }
    //printf("nums[%d]=%d\n", j, nums[j]);
    if(i!=j){
        nums[i] = nums[j];
        nums[j] = current;
    }

    //reverse
    int m=i+1;
    int n=numsSize-1;
    for(; m<n; m++, n--){
        int temp=nums[m];
        nums[m]=nums[n];
        nums[n]=temp;
    }
}

/*==============================================================*/
int main(){
    int test[]={1,1};
    int numsSize = sizeof(test)/sizeof(int);
    //printf("Size : %d\n", numsSize);

    printf("Input is : ");
    for(int i=0; i<numsSize; i++){
        printf("%d ", test[i]);
    }
    printf("\n");

    nextPermutation(test, numsSize);

    printf("Answer is : ");
    for(int i=0; i<numsSize; i++){
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/