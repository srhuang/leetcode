/*****************************************************************
Name    :generateMatrix
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
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
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    //prepare result array
    int **result = malloc(sizeof(int*) * n);
    for(int i=0; i<n; i++){
        result[i] = malloc(sizeof(int) * n);
    }

    int row_min=0;
    int row_max=n-1;
    int col_min=0;
    int col_max=n-1;

    int count = 0;
    while(count < n*n){
        //from left to right
        for(int i=col_min; i<=col_max; i++){
            result[row_min][i] = ++count;
        }

        //from up to down
        for(int i=row_min+1; i<=row_max; i++){
            result[i][col_max] = ++count;
        }

        //from right to left
        for(int i=col_max-1; i>=col_min; i--){
            result[row_max][i] = ++count;
        }

        //from down to up
        for(int i=row_max-1; i>row_min; i--){
            result[i][col_min] = ++count;
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
    int n = 1;

    int **answer = generateMatrix(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%2d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*==============================================================*/