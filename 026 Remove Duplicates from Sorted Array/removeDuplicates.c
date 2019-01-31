/*****************************************************************
Name    :removeDuplicates
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190131 Initial Version
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
    int parsing = 0;
    int answer=0;

    if(0 == numsSize)
        return answer;

    while(parsing<numsSize){
        
        while((parsing<numsSize) && (nums[answer] == nums[parsing])){
            parsing++;
        }
        if(parsing<numsSize){
            nums[++answer] = nums[parsing];
            printf("nums[%d]=%d \n", answer, nums[parsing]);
        }
    }
    return ++answer;
}

/*==============================================================*/
int main(){
    int test[10] = {0,0,0,1,1,1,2,2,2,3};
    int size = sizeof(test)/sizeof(int);

    printf("Input is : ");
    for(int i=0; i<size; i++){
        printf("%d ", test[i]);
    }
    printf("\n");

    int answer_size=removeDuplicates(test, size);

    printf("Answer is : ");
    for(int i=0; i<answer_size; i++){
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/