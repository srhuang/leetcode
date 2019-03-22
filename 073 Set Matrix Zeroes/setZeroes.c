/*****************************************************************
Name    :setZeroes
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190322 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int *zeroRow = calloc(matrixRowSize, sizeof(int));
    int *zeroCol = calloc(matrixColSize, sizeof(int));

    //parsing each element
    for(int i=0; i<matrixRowSize; i++){
        for(int j=0; j<matrixColSize; j++){
            if(0==matrix[i][j]){
                zeroRow[i] = 1;
                zeroCol[j] = 1;
            }
        }
    }

    //set zero accroding to zero array
    for(int i=0; i<matrixRowSize; i++){
        for(int j=0; j<matrixColSize; j++){
            if(1==zeroRow[i] || 1==zeroCol[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

/*==============================================================*/
int main(){
    int test_data[3][4]={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    int row = sizeof(test_data)/sizeof(test_data[0]);
    int col = sizeof(test_data[0])/sizeof(int);
    printf("row : %d, col : %d\n", row, col);
    int **matrix = malloc(sizeof(int*)*row);
    for(int i=0; i<row; i++){
        matrix[i] = test_data[i];
    }

    setZeroes(matrix, row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*==============================================================*/