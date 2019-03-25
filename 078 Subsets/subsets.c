/*****************************************************************
Name    :subsets
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190325 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int *nums, int numsSize, int** columnSizes, int* returnSize, int ***result, int *track, int first, int depth)
{
    if(first > numsSize)
        return;

    //printf("first:%d, depth:%d\n", first, depth);
    //add track into result
    (*returnSize)++;
    (*result) = realloc((*result), sizeof(int*)*(*returnSize));
    (*columnSizes) = realloc((*columnSizes), sizeof(int)*(*returnSize));

    //copy track to result
    int *solution = malloc(sizeof(int)*depth);
    for(int i=0; i<depth; i++){
        solution[i] = track[i];
    }
    (*result)[(*returnSize)-1] = solution;
    (*columnSizes)[(*returnSize)-1] = depth;

    //backtrack
    for(int i=first; i<numsSize; i++){
        //printf("track[%d]=%d\n", depth, nums[i]);
        track[depth] = nums[i];
        backtrack(nums, numsSize, columnSizes, returnSize, result, track, i+1, depth+1);
    }

}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **result = malloc(sizeof(int*));
    (*columnSizes) = malloc(sizeof(int));
    int *track = calloc(numsSize, sizeof(int));

    backtrack(nums, numsSize, columnSizes, returnSize, &result, track, 0, 0);

    return result;
}

/*==============================================================*/
int main(){
    int nums[] = {2,3,4};
    int size = sizeof(nums)/sizeof(int);
    int **columnSizes = malloc(sizeof(int*));
    int returnSize;

    int **answer = subsets(nums, size, columnSizes, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("columnSizes : %d ", (*columnSizes)[i]);
        for(int j=0; j<(*columnSizes)[i]; j++){
            printf(" %d", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*==============================================================*/