/*****************************************************************
Name    :permuteUnique
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190227 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
int compare(const void* arg1, const void* arg2){
    return *(const int*)arg1 - *(const int*)arg2;
}

/*==============================================================*/
//Function area
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    //sort input data first
    qsort(nums, numsSize, sizeof(int), compare);

    //calculate the number of answers
    int count=1;
    for(int i=1; i<=numsSize; i++){
        count *= i;
    }
    //printf("# of Answer is %d\n", count);

    //malloc all answers
    int **result = malloc(sizeof(int*) * count);

    //first permutation
    *returnSize = 0;
    result[*returnSize] = malloc(sizeof(int) * numsSize);
    for(int i=0; i<numsSize; i++){
        result[*returnSize][i] = nums[i];
    }
    (*returnSize)++;

    //find next permutation
    while(1){
        //find the anchor
        int anchor;
        for(anchor=numsSize-2; anchor>=0; anchor--){
            if(nums[anchor] < nums[anchor+1])
                break;
        }
        //break the while loop when meet last permutation
        if(-1 == anchor)
            break;

        //swap
        int pivot;
        for(pivot=numsSize-1; pivot>anchor; pivot--){
            if(nums[pivot] > nums[anchor])
                break;
        }
        if(pivot != anchor){
            int temp = nums[anchor];
            nums[anchor] = nums[pivot];
            nums[pivot] = temp;
        }

        //reverse the last substring
        int head=anchor+1;
        int end=numsSize-1;
        while(head<end){
            int temp = nums[head];
            nums[head] = nums[end];
            nums[end] = temp;
            head++;
            end--;
        }

        //record the result
        result[*returnSize] = malloc(sizeof(int) * numsSize);
        //printf("Result is ");
        for(int i=0; i<numsSize; i++){
            result[*returnSize][i] = nums[i];
            //printf("%d ", nums[i]);
        }
        //printf("\n");
        (*returnSize)++;
    }//while

    return result;
}

/*==============================================================*/
int main(){
    int test_data[] = {2,2,1,1};
    int size = sizeof(test_data)/sizeof(int);
    int returnSize = 0;

    int **answer = permuteUnique(test_data, size, &returnSize);
    printf("Answer is : \n[\n");
    for(int i=0; i<returnSize; i++){
        printf("\t[ ");
        for(int j=0; j<size; j++){
            printf("%d ", answer[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");

    return 0;
}
/*==============================================================*/