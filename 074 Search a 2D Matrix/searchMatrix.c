/*****************************************************************
Name    :searchMatrix
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
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(0==matrixRowSize || 0==matrixColSize)
        return false;
    //treat it as sorted list
    int left = 0;
    int right = matrixRowSize*matrixColSize-1;
    while(left<right){
        int mid = (left+right) / 2;
        if(matrix[mid/matrixColSize][mid%matrixColSize] < target){
            left = mid+1;
        }else{
            right = mid;
        }
    }

    return target == matrix[left/matrixColSize][left%matrixColSize];
}

/*==============================================================*/
int main(){
    int test_data[3][4]={
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int row = sizeof(test_data)/sizeof(test_data[0]);
    int col = sizeof(test_data[0])/sizeof(int);
    printf("row:%d, col:%d\n", row, col);
    int **matrix = malloc(sizeof(int*)*row);
    for(int i=0; i<row; i++){
        matrix[i] = test_data[i];
    }

    bool answer = searchMatrix(matrix, row, col, 13);
    printf("Answer is %d", answer);

    return 0;
}
/*==============================================================*/