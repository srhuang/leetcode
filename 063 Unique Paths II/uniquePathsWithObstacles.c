/*****************************************************************
Name    :uniquePathsWithObstacles
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
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    long **grid = malloc(sizeof(long*)*obstacleGridRowSize);
    for(int i=0; i<obstacleGridRowSize; i++){
        grid[i] = malloc(sizeof(long) * obstacleGridColSize);
        for(int j=0; j<obstacleGridColSize; j++){
            grid[i][j] = obstacleGrid[i][j];
        }
    }

    //dynamic programming
    //check the first position
    if(1 == grid[0][0]){
        return 0;
    }else{
        grid[0][0] = 1;
    }

    //fill up the first row
    for(int j=1; j<obstacleGridColSize; j++){
        if(1 == grid[0][j]){
            grid[0][j]=0;
        }else{
            grid[0][j] = grid[0][j-1];
        }
    }

    //fill up the first col
    for(int i=1; i<obstacleGridRowSize; i++){
        if(1 == grid[i][0]){
            grid[i][0]=0;
        }else{
            grid[i][0] = grid[i-1][0];
        }
    }

    //fill the last values
    for(int i=1; i<obstacleGridRowSize; i++){
        for(int j=1; j<obstacleGridColSize; j++){
            if(1 == grid[i][j]){
                grid[i][j]=0;
            }else{
                grid[i][j] = grid[i][j-1] + grid[i-1][j];
                printf("grid[%d][%d]=%ld\n", i, j, grid[i][j]);
            }
        }
    }

    return grid[obstacleGridRowSize-1][obstacleGridColSize-1];
}

/*==============================================================*/
int main(){
    int test[3][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    int row = sizeof(test)/sizeof(test[0]);
    int col = sizeof(test[0])/sizeof(int);
    printf("row:%d, col:%d\n", row, col);


    int **obstacleGrid = malloc(sizeof(int*) * row);
    for(int i=0; i<row; i++){
        obstacleGrid[i] = malloc(col*sizeof(int));
        for(int j=0; j<col; j++){
            obstacleGrid[i][j] = test[i][j];
        }
    }

    int answer = uniquePathsWithObstacles(obstacleGrid, row, col);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/