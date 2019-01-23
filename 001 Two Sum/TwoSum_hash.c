/*****************************************************************
Name    :TwoSum_hash
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190122 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *solution=malloc(2 * sizeof(int));
    int min = nums[0];
    int max = nums[0];

    //find the min and max
    for(int i=0; i<numsSize; i++){
        if(nums[i]>max){
            max=nums[i];
        }

        if(nums[i]<min){
            min=nums[i];
        }
    }

    //construct hash table
    int *complement = (int*)calloc((max-min+1), sizeof(int));
    int diff;
    for(int i=0; i<numsSize; i++){
        diff = target - nums[i];
        if((diff<=max) && (diff>=min)){
            complement[diff-min]=i;
        }
    }

    //using hash table find answer
    for(int i=0; i<numsSize; i++){
        int comp_index = complement[nums[i]-min];
        if(comp_index != 0){
            //exclude the same indices
            if(i != comp_index){
                solution[0] = i;
                solution[1] = comp_index;
                return solution;
            }
        }
    }

    return NULL;
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