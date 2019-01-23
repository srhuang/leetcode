/*****************************************************************
Name    :threeSum
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190122 Initial Version
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

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **result = (int**)malloc(sizeof(int*) * (numsSize) * (numsSize));
    int **result_ptr = result;

    //sort before parsing
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i=0; i<numsSize; i++){
        printf ("%d ",nums[i]);
    }
    printf("\n");

    for(int i=0; i<numsSize-2; i++){
        int a = nums[i];

        //promote the performance
        if(a>0)
            break;

        //handle the same value
        if(i>0 && a==nums[i-1])
            continue;

        for(int j=i+1, k=numsSize-1; j<k;){
            int b = nums[j];
            int c = nums[k];
            int value = a+b+c;
            if(0 == value){
                printf("nums[%d]=%d, nums[%d]=%d, nums[%d]=%d\n", i, a, j, b, k, c);
                int *answer = (int*)calloc(3, sizeof(int));
                answer[0]=a;
                answer[1]=b;
                answer[2]=c;
                *result_ptr = answer;
                result_ptr++;

                (*returnSize)++;
                //skip the same values
                while(j<k && b==nums[++j]);
                while(j<k && c==nums[--k]);
            }else if(value > 0){
                k--;
            }else{
                j++;
            }
        }//for j,k
    }//for i

    return result;
}

/*==============================================================*/
int main(){
    int test[6] = {-1, 0, 1, 2, -1, -4};

    int returnSize;
    int **answer=threeSum(test, sizeof(test)/sizeof(int), &returnSize);
    printf("There are %d answers\n", returnSize);
    //printf("FFF:%d\n", (*answer)[1]);

    //print all values
    for(int i=0; i<returnSize; i++){
        int *each_answer = *answer;
        printf("Addr : %d\n", each_answer);
        for(int j=0; j<3; j++){
            printf("Value : %d\n", *each_answer);
            //printf("[%d, %d, %d]\n", each_answer);
            each_answer++;
        }
        answer++;
    }

    return 0;
}
/*==============================================================*/
