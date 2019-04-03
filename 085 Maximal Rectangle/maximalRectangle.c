/*****************************************************************
Name    :maximalRectangle
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190401 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MAX(a,b) ((a)>(b)?(a):(b))

/*==============================================================*/
//Function area
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if(0==matrixRowSize || 0==matrixColSize){
        return 0;
    }
    int *height = calloc(matrixColSize, sizeof(int));
    int *leftLower = malloc(sizeof(int) * matrixColSize);
    int *rightLower = malloc(sizeof(int) * matrixColSize);
    int max_area = 0;

    for(int i=0; i<matrixRowSize; i++){
        //calculate the height
        for(int j=0; j<matrixColSize; j++){
            if(matrix[i][j] == '1'){
                height[j]++;
            }else{
                height[j]=0;
            }
            //printf("height[%d]=%d\n", j, height[j]);
        }

        //calculate the left lower
        leftLower[0]=-1;
        for(int j=1; j<matrixColSize; j++){
            int index = j-1;
            while(index>=0 && height[index]>=height[j]){
                index = leftLower[index];
            }
            leftLower[j] = index;
            //printf("leftLower[%d]=%d\n", j, leftLower[j]);
        }

        //calculate the right lower
        rightLower[matrixColSize-1] = matrixColSize;
        for(int j=matrixColSize-2; j>=0; j--){
            int index = j+1;
            while(index<matrixColSize && height[index]>=height[j]){
                index = rightLower[index];
            }
            rightLower[j] = index;
            //printf("rightLower[%d]=%d\n", j, rightLower[j]);
        }

        //calculate the max area by leftLower and rightLower
        for(int j=0; j<matrixColSize; j++){
            max_area = MAX(max_area, height[j] * (rightLower[j]-leftLower[j]-1));
        }
        //printf("max area:%d\n", max_area);
    }//for each row

    return max_area;
}

/*==============================================================*/
int main(){
    char test[4][5] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };

    int row = sizeof(test)/sizeof(test[0]);
    int col = sizeof(test[0])/sizeof(char);
    char **matrix = malloc(sizeof(char*)*row);
    for(int i=0; i<row; i++){
        matrix[i] = test[i];
    }

    int answer = maximalRectangle(matrix, row, col);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/