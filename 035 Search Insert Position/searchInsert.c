/*****************************************************************
Name    :searchInsert
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190214 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
    int searchInsert(int* nums, int numsSize, int target) {
        //binary search
        int lo=0;
        int hi=numsSize-1;
        while(lo<hi-1){
            printf("lo=%d, hi=%d\n", lo, hi);
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                lo=mid;
            }else{
                hi=mid;
            }
        }
        printf("lo=%d, hi=%d\n", lo, hi);

        //handle the edge value
        if(0 == lo && nums[lo]>=target)
            return 0;
        if(hi == numsSize-1 && nums[hi]<target)
            return numsSize;
        
        return hi;
    }

/*==============================================================*/
int main(){
    int test[] = {1,3,5,7,9};
    int size = sizeof(test)/sizeof(int);

    int answer = searchInsert(test, size, 9);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/