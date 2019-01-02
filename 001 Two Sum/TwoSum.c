/*****************************************************************
Name	:TwoSum
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181229 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *solution=malloc(2 * sizeof(int));
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if((nums[i]+nums[j]) == target){
                solution[0]=i;
                solution[1]=j;
                break;
            }
        }
    }
    return solution;
}

/*==============================================================*/
int main(){
    int test_data[4] = {2, 7, 11, 15};
    int test_data_size = sizeof(test_data)/sizeof(int);
    int target = 9;

    int *answer = twoSum(test_data, test_data_size, target);

    printf("Test data size : %d\n", test_data_size);
    printf("Test data : ");
    for(int i=0; i<test_data_size; i++){
        printf("%d\t", test_data[i]);
    }

    printf("\nThe answer is : %d, %d\n", answer[0], answer[1]);

    free(answer);
    return 0;
}
/*==============================================================*/