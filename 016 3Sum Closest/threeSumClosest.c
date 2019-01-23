/*****************************************************************
Name    :threeSumClosest
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190123 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*==============================================================*/
int compare(const void *arg1, const void *arg2) {
    return (*(const int *)arg1 - *(const int *)arg2);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int closest_value;
    int closest_diff = INT_MAX;

    //sort before parsing
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i=0; i<numsSize-2; i++){
        int a = nums[i];


        for(int j=i+1, k=numsSize-1; j<k;){
            int b = nums[j];
            int c = nums[k];
            int value = a+b+c;
            int diff = abs(target-value);
            printf("(%d, %d, %d) : value=%d, diff=%d\n", i, j, k, value, diff);
            if(diff<closest_diff){
                printf("\tUpdate the closest value : %d\n", value);
                closest_diff = diff;
                closest_value = value;
            }

            if(value == target){
                return target;
            }else if(value > target){
                k--;
            }else{
                j++;
            }
        }//for j, k
    }//for i
    
    return closest_value;
}

/*==============================================================*/
int main(){
    int test[3] = {0,1,2};

    int answer = threeSumClosest(test, sizeof(test)/sizeof(int), 3);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/