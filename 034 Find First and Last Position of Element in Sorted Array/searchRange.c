/*****************************************************************
Name    :searchRange
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190213 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    *returnSize=2;

    if(0 == numsSize){
        result[0]=-1;
        result[1]=-1;
        return result;
    }

    //binary search to find the leftmost target
    int lo=0;
    int hi=numsSize-1;
    while(lo < hi){
        int mid=(lo+hi)/2;
        if(target > nums[mid]){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    printf("lo=%d, hi=%d\n", lo, hi);
    if(nums[hi] != target)
        result[0]=-1;
    else
        result[0] = hi;

    //binary searchto find the rigtmost target
    lo=0;
    hi=numsSize-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(target < nums[mid]){
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    printf("lo=%d, hi=%d\n", lo, hi);
    int rightmost = (lo-1)>=0 && (nums[lo]!=target) ? (lo-1) : (lo);
    printf("rightmost : %d\n", rightmost);
    if(nums[rightmost] != target)
        result[1] = -1;
    else
        result[1] = rightmost;

    return result;
}

/*==============================================================*/
int main(){
    int test[] = {2,2,4,5};
    int size = sizeof(test)/sizeof(int);
    printf("size : %d\n", size);
    int returnSize=0;

    int *answer = searchRange(test, size, 3, &returnSize);
    printf("Answer is : ");
    for(int i=0; i< returnSize; i++){
        printf("%d ", answer[i]);
    }

    return 0;
}
/*==============================================================*/