/*****************************************************************
Name    :fourSum
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190124 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *arg1, const void *arg2) {
    return (*(const int *)arg1 - *(const int *)arg2);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    //sort before parsing
    qsort(nums, numsSize, sizeof(int), compare);

    int **result = (int**)malloc(sizeof(int*) * numsSize * numsSize *numsSize);
    int **result_ptr = result;

    for(int i=0; i<numsSize-3; i++){
        int a=nums[i];

        //skip no use parsing
        if(a>0 && a>target)
            break;
        //handle the same value
        if(i>0 && a==nums[i-1])
            continue;

        //the same as three sum
        for(int j=i+1; j<numsSize-2; j++){
            int b=nums[j];
            if(b>0 && b>(target-a))
                break;
            if(j>i+1 && b==nums[j-1])
                continue;
            for(int k=j+1, l=numsSize-1; k<l;){
                int c=nums[k];
                int d=nums[l];
                int value = a+b+c+d;
                if(value == target){
                    printf("nums[%d]=%d, nums[%d]=%d, nums[%d]=%d, nums[%d]=%d\n", 
                        i, a, j, b, k, c, l, d);
                    //prepare the data
                    int *answer = (int*)calloc(4, sizeof(int));
                    answer[0]=a;
                    answer[1]=b;
                    answer[2]=c;
                    answer[3]=d;
                    *result_ptr=answer;
                    result_ptr++;

                    (*returnSize)++;

                    //skip the same values
                    while(k<l && c==nums[++k]);
                    while(k<l && d==nums[--l]);

                }else if(value<target){
                    k++;
                }else{
                    l--;
                }
            }
        }

    }
    
    return result;
}

/*==============================================================*/
int main(){
    int test[8] = {1,-2,-5,-4,-3,3,3,5};

    int returnSize=0;
    int **answer = fourSum(test, sizeof(test)/sizeof(int), -11, &returnSize);

    //print all answers
    for(int i=0; i<returnSize; i++){
        int size = 4;
        printf("[");
        for(int j=0; j<size; j++){
            printf("%d ", answer[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
/*==============================================================*/
