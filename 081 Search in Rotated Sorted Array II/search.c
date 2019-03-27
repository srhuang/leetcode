/*****************************************************************
Name    :search
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
bool search(int* nums, int numsSize, int target) {
    //for empty
    if(0==numsSize)
        return false;
    int left = 0;
    int right = numsSize-1;
    while(left<right){
        
        int mid=(left+right)/2;
        //printf("before : left:%d, right:%d, mid:%d\n", left, right, mid);
        if(nums[mid] == target){
            return true;
        }

        //check the location of target
        if(nums[left] < nums[mid]){
            if(target >= nums[left] && target < nums[mid]){
                right = mid-1;
            }else{
                left=mid+1;
            }
        }else if(nums[left] > nums[mid]){
            if(target > nums[mid] && target <= nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }else{
            left++;
        }
        //printf("after : left:%d, right:%d, mid:%d\n", left, right, mid);
    }//while

    return nums[left]==target?true:false;
}

/*==============================================================*/
int main(){
    int nums[] = {2,5,6,0,0,1,2};
    int size = sizeof(nums)/sizeof(int);

    bool answer = search(nums, size, 3);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/