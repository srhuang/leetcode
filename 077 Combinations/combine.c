/*****************************************************************
Name    :combine
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
void backtrack(int n, int k, int** columnSizes, int* returnSize, int first, int depth, int *track, int ***result)
{
    if(first>n)
        return;

    //printf("first:%d, depth:%d\n", first, depth);
    //terminal
    if(depth == k){
        (*returnSize)++;
        (*result) = realloc((*result), sizeof(int*)*(*returnSize));
        (*columnSizes) = realloc((*columnSizes), sizeof(int)*(*returnSize));

        //copy the track to result
        int *solution = malloc(sizeof(int)*k);
        for(int i=0; i<k; i++){
            solution[i] = track[i];
        }
        (*result)[(*returnSize)-1] = solution;
        (*columnSizes)[(*returnSize)-1] = k;

        return;
    }

    for(int i=first; i<=n; i++){

        track[depth] = (i+1);
        backtrack(n, k, columnSizes, returnSize, i+1, depth+1, track, result);
    }
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int *track = malloc(sizeof(int)*k);
    int **result = malloc(sizeof(int*));
    (*columnSizes) = malloc(sizeof(int));
    
    backtrack(n, k, columnSizes, returnSize, 0, 0, track, &result);

    return result;
}

/*==============================================================*/
int main(){
    int n = 6;
    int k = 3;
    int returnSize = 0;
    int **columnSizes = malloc(sizeof(int*));

    int **answer = combine(n, k, columnSizes, &returnSize);
    printf("returnSize : %d\n", returnSize);
    
    for(int i=0; i<returnSize; i++){
        printf("columnSizes:%d ", (*columnSizes)[i]);
        printf("[");
        for(int j=0; j<k; j++){
            printf(" %d", answer[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
/*==============================================================*/