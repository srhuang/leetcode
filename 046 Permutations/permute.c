/*****************************************************************
Name    :permute
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190225 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*==============================================================*/
//Function area
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(int *nums, int numsSize, int ***result, int* returnSize, int head)
{
    //Handle leaf
    if(head == numsSize-1){
        (*returnSize)++;
        *result = realloc(*result, sizeof(int*) * (*returnSize));

        //prepare the result
        (*result)[(*returnSize)-1] = malloc(sizeof(int) * numsSize);
        for(int i=0; i<numsSize; i++){
            (*result)[(*returnSize)-1][i] = nums[i];
        }

        return;
    }

    //try to use each element as the head
    for(int i=head; i<numsSize; i++){ 
        swap(nums+head, nums+i);
        DFS(nums, numsSize, result, returnSize, head+1);
        swap(nums+head, nums+i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    
    int **answer = malloc(sizeof(int*));
    DFS(nums, numsSize, &answer, returnSize, 0);
    return answer;
}

/*==============================================================*/
int main(){
    int nums[] = {1,2,3,4,5};
    int size = sizeof(nums)/sizeof(int);
    int returnSize = 0;

    int **answer = permute(nums, size, &returnSize);
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