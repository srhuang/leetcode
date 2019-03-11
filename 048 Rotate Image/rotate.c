/*****************************************************************
Name    :rotate
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190227 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*==============================================================*/
//Function area
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    
    //reverse up to down
    for(int i=0; i<matrixRowSize/2; i++){
        int down_row = matrixRowSize-i-1;
        for(int j=0; j<(*matrixColSizes) ; j++){
            swap(&matrix[i][j], &matrix[down_row][j]);
        }
    }

    //swap symmetry
    for(int i=0; i<matrixRowSize; i++){
        for(int j=i+1; j<(*matrixColSizes); j++){
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

/*==============================================================*/
int main(){
    int test_data[3][3] ={
        {1,2,3}, 
        {4,5,6}, 
        {7,8,9}
    }; 

    int row=3;
    int col=3;
    int **matrix = malloc(sizeof(int*)*row);
    for(int i=0; i<row; i++){
        matrix[i] = malloc(sizeof(int) * col);
        for(int j=0; j<col; j++){
            matrix[i][j] = test_data[i][j];
        }
    }

    rotate(matrix, row, &col);

    printf("Answer is \n[");
    for(int i=0; i<row; i++){
        printf("\n");
        for(int j=0; j<col; j++){
            printf(" %d", matrix[i][j]);
        }
    }
    printf("\n]\n");

    return 0;
}
/*==============================================================*/