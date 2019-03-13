/*****************************************************************
Name    :spiralOrder
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190313 Initial Version
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int total_size = matrixRowSize * matrixColSize;
    int *result = malloc(sizeof(int) * total_size);
    int row_min = 0;
    int row_max = matrixRowSize-1;
    int col_min = 0;
    int col_max = matrixColSize-1;

    int count=0;
    while(count<total_size){
        //from left to right
        for(int i=col_min; i<=col_max; i++){
            result[count++] = matrix[row_min][i];
        }

        //only one row
        if(count == total_size) break;

        //from up to down
        for(int i=row_min+1; i<=row_max; i++){
            result[count++] = matrix[i][col_max];
        }

        //only one col
        if(count == total_size) break;

        //from right to left
        for(int i=col_max-1; i>=col_min; i--){
            result[count++] = matrix[row_max][i];
        }

        //from down to up
        for(int i=row_max-1; i>row_min; i--){
            result[count++] = matrix[i][col_min];
        }

        //shrink the area
        row_min += 1;
        row_max -= 1;
        col_min += 1;
        col_max -= 1;
    }

    return result;
}

/*==============================================================*/
int main(){
    int test[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int row = sizeof(test)/sizeof(test[0]);
    int col = sizeof(test[0])/sizeof(int);
    printf("row:%d, col:%d\n", row, col);

    int **input = malloc(sizeof(int*)*row);
    for(int i=0; i<col; i++){
        input[i] = test[i];
    }

    int *answer = spiralOrder(input, row, col);
    printf("Answer is [");
    for(int i=0; i<(row*col); i++){
        printf(" %d", answer[i]);
    }
    printf("]\n");

    return 0;
}
/*==============================================================*/