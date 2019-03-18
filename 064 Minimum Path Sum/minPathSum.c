/*****************************************************************
Name    :minPathSum
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190315 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MIN(a,b) ((a)<(b)?(a):(b))

/*==============================================================*/
//Function area
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    
    //Dynamic programming
    for(int i=0; i<gridRowSize; i++){
        for(int j=0; j<gridColSize; j++){
            if(0==i && 0==j){
                grid[i][j] = grid[i][j];
            }else if(0==i && 0!=j){
                grid[i][j] += grid[i][j-1];
            }else if(0!=i && 0==j){
                grid[i][j] += grid[i-1][j];
            }else{
                grid[i][j] += MIN(grid[i-1][j], grid[i][j-1]);
            }
        }
    }

    return grid[gridRowSize-1][gridColSize-1];
}

/*==============================================================*/
int main(){
    int test_data[3][3]={
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    int row = sizeof(test_data)/sizeof(test_data[0]);
    int col = sizeof(test_data[0])/sizeof(int);
    printf("row=%d, col=%d\n", row, col);

    int **grid = malloc(sizeof(int*)*row);
    for(int i=0; i<row; i++){
        grid[i] = malloc(sizeof(int)*col);
        for(int j=0; j<col; j++){
            grid[i][j] = test_data[i][j];
        }
    }

    int answer = minPathSum(grid, row, col);
    printf("Answer is :%d\n", answer);

    return 0;
}
/*==============================================================*/