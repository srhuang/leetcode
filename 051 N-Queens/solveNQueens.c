/*****************************************************************
Name    :solveNQueens
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190312 Initial Version
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrack(int x, int y, int n, int queen, int **chessboard, int **flag, char ****result, int *returnSize)
{
    if(n==y){
        x++;
        y=0;
    }

    if(n==x){
        if(queen != n) return;
        //add into result
        //printf("Bingo!\n");
        (*returnSize)++;
        (*result)=realloc((*result), sizeof(char**) * (*returnSize));

        //prepare solution
        char **solution = malloc(sizeof(char*) * n);
        for(int i=0; i<n; i++){
            solution[i] = malloc(sizeof(char) * (n+1));
            for(int j=0; j<n; j++){
                solution[i][j] = chessboard[i][j] ? 'Q' : '.';
            }
            solution[i][n] = '\0';
        }

        int index = (*returnSize)-1;
        (*result)[index] = solution;
        return;
    }

    int d1 = (x+y) % (2*n-1);
    int d2 = (x-y+(2*n-1)) % (2*n-1);
    //printf("x : %d, y : %d, d1 : %d, d2 : %d\n", x, y, d1, d2);
    if(!flag[0][x] && !flag[1][y] && !flag[2][d1] && !flag[3][d2]){
        flag[0][x] = flag[1][y] = flag[2][d1] = flag[3][d2] = 1;
        chessboard[x][y] = 1;
        backtrack(x, y+1, n, queen+1, chessboard, flag, result, returnSize);
        flag[0][x] = flag[1][y] = flag[2][d1] = flag[3][d2] = 0;
    }

    chessboard[x][y] = 0;
    backtrack(x, y+1, n, queen, chessboard, flag, result, returnSize);
}
char*** solveNQueens(int n, int* returnSize) {
    int **chessboard = malloc(sizeof(int*) * n);
    for(int i=0; i<n; i++){
        chessboard[i] = calloc(n, sizeof(int));
    }
    int **flag = malloc(sizeof(int*) * 4);
    for(int i=0; i<4; i++){
        flag[i] = calloc(2*n, sizeof(int));
    }

    char ***result = malloc(sizeof(char**));
    backtrack(0, 0, n, 0, chessboard, flag, &result, returnSize);
    return result;
}

/*==============================================================*/
int main(){
    int returnSize = 0;
    int n=4;

    char ***answer = solveNQueens(n, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("[\n");
        for(int j=0; j<n; j++){
            printf("\t%s\n", answer[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
/*==============================================================*/