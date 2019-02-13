/*****************************************************************
Name    :search
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
int search(int* nums, int numsSize, int target) {
    //find the smallest element
    int lo = 0;
    int hi = numsSize-1;
    while(lo<hi){
        int mid = (lo+hi) / 2;
        if(nums[mid] > nums[hi]){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    printf("lo=%d, hi=%d\n", lo, hi);

    //binary search with rotation
    int rot=lo;
    lo=0;
    hi=numsSize-1;
    while(lo<=hi){
        int mid=(lo+hi) / 2;
        int rotationMid = (mid+rot)%numsSize;
        if(nums[rotationMid] == target)
            return rotationMid;
        if(nums[rotationMid] < target){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }

    return -1;
}

/*==============================================================*/
int main(){
    int test[] = {4,5,6,7,0,1,2};
    int size = sizeof(test)/sizeof(int);
    printf("size : %d\n", size);

    int answer = search(test, size, 7);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/