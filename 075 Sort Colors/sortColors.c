/*****************************************************************
Name    :sortColors
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190322 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
void swap(int *arg1, int *arg2)
{
    int temp=*arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

/*==============================================================*/
//Function area
void sortColors(int* nums, int numsSize) {
    int zero=0;
    int two=numsSize-1;
    for(int i=0; i<numsSize; i++){
        while(nums[i]==2 && i<two){
            swap(&nums[i], &nums[two--]);
        }
        while(nums[i]==0 && i>zero){
            swap(&nums[i], &nums[zero++]);
        }
    }
}

/*==============================================================*/
int main(){
    int nums[] = {1,0};
    int size = sizeof(nums)/sizeof(int);

    sortColors(nums, size);
    for(int i=0; i<size; i++){
        printf(" %d", nums[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/