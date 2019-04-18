/*****************************************************************
Name    :grayCode
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    
    *returnSize = 1;
    int *result = calloc((*returnSize), sizeof(int));
    int msb = 1;

    for(int i=1; i<=n; i++){
        *returnSize *= 2;
        printf("returnSize : %d\n", *returnSize);
        result = realloc(result, (*returnSize)*sizeof(int));

        //reverse and multiply by msb
        //printf("i=%d\n", i);
        int sym=0;
        for(int j=(*returnSize)/2; j<(*returnSize); j++){
            printf("j=%d, j-2*sym-1=%d\n", j, j-2*sym-1);
            result[j] = result[j-2*sym-1]+msb;
            //printf("result[%d]=%d\n", j, result[j]);
            sym++;
        }
         msb *= 2;

    }//for

    return result;
}

/*==============================================================*/
int main(){
    int returnSize=0;

    int *answer = grayCode(2, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf(" %d", answer[i]);
    }

    return 0;
}
/*==============================================================*/