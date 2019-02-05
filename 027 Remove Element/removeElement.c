/*****************************************************************
Name    :removeElement
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
int removeElement(int* nums, int numsSize, int val) {
    int *tail = nums;
    int answer = 0;

    if(nums == NULL)
        return 0;

    printf("Parsing each element : ");
    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);

        if(nums[i] != val){
            *tail = nums[i];
            tail++;
            answer++;
        }
    }
    printf("\n");

    return answer;
}

/*==============================================================*/
int main(){
    int test[8] = {0,1,2,2,3,0,4,2};
    int size = sizeof(test)/sizeof(int);

    int answer = removeElement(test, size, 2);
    printf("Answer is : %d \n", answer);

    //parsing all element
    printf("After removing : ");
    for(int i=0; i<answer; i++){
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/