/*****************************************************************
Name    :maxSubArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190313 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int maxSubArray(int* nums, int numsSize) {
    int sum=0;
    int max = INT_MIN;

    for(int i=0; i<numsSize; i++){
        if(sum >= 0){
            sum += nums[i];
        }else{
            sum = nums[i];
        }

        //check maximum
        if(sum > max)
            max = sum;
    }

    return max;
}

/*==============================================================*/
int main(){
    int test_data[] = {-2,1,-3,4,-1,2,1,-5,4};

    int answer = maxSubArray(test_data, sizeof(test_data)/sizeof(int));
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/