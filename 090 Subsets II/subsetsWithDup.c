/*****************************************************************
Name    :subsetsWithDup
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190418 Initial Version
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
int compare(const void *arg1, const void *arg2)
{
    return *(const int*)arg1 - *(const int*)arg2;
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    //sort
    qsort(nums, numsSize, sizeof(int), compare);
    //prepare
    int **result = malloc(sizeof(int*));
    (*columnSizes) = malloc(sizeof(int));
    (*returnSize) = 0;

    //deafult empty subset
    (*returnSize)++;
    result = realloc(result, sizeof(int*)*(*returnSize));
    (*columnSizes) = realloc((*columnSizes), sizeof(int)*(*returnSize));
    result[(*returnSize)-1]=NULL;
    (*columnSizes)[(*returnSize)-1]=0;


    for(int i=0; i<numsSize;){
        //count the duplication
        int count=0;
        while((i+count<numsSize)&&(nums[i]==nums[i+count])) count++;
        //printf("count = %d\n", count);

        //for each previous subset, there are 'count' combinations
        int pre_returnSize = (*returnSize);
        for(int j=0; j<pre_returnSize; j++){
            //printf("j=%d, size=%d\n", j, *returnSize);

            int *current_subset = result[j];
            int subset_size = (*columnSizes)[j];
            //printf("subset_size:%d\n", subset_size);
            for(int k=1; k<=count; k++){
                int *new_subset = malloc(sizeof(int)*(subset_size+k));
                if(current_subset!=NULL)
                    memcpy(new_subset, current_subset, sizeof(int)*subset_size);
                for(int m=0; m<k; m++){
                    //printf("m=%d\n", m);
                    new_subset[subset_size+m]=nums[i];
                }
                //add into result
                (*returnSize)++;
                result = realloc(result, sizeof(int*)*(*returnSize));
                (*columnSizes) = realloc((*columnSizes), sizeof(int)*(*returnSize));
                result[(*returnSize)-1]=new_subset;
                (*columnSizes)[(*returnSize)-1]=subset_size+k;
            }
        }//for

        i+=count;
    }

    return result;
}

/*==============================================================*/
int main(){
    int nums[] = {1,2,2};
    int size = sizeof(nums)/sizeof(int);

    int **columnSizes = malloc(sizeof(int*));
    int returnSize;

    int **answer = subsetsWithDup(nums, size, columnSizes, &returnSize);
    printf("returnSize : %d\n", returnSize);
    printf("Answer is \n");
    for(int i=0; i<returnSize; i++){
        //printf("columnSizes %d : %d\n", i, (*columnSizes)[i]);
        printf("[");
        for(int j=0; j<(*columnSizes)[i]; j++){
            printf(" %d", answer[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
/*==============================================================*/