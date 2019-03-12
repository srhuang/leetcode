/*****************************************************************
Name    :totalNQueens
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
void backtrack(int x, int y, int n, int queen, int **chessboard, int **flag, int *returnSize)
{
    if(y==n){
        x++;
        y=0;
    }

    if(x==n){
        if(queen != n)
            return;
        (*returnSize)++;
        return;
    }

    int d1 = (x+y) % (2*n-1);
    int d2 = ((x-y)+(2*n-1)) % (2*n-1);
    if(!flag[0][x] && !flag[1][y] && !flag[2][d1] && !flag[3][d2]){
        flag[0][x] = flag[1][y] = flag[2][d1] = flag[3][d2] = 1;
        chessboard[x][y] = 1;
        backtrack(x, y+1, n, queen+1, chessboard, flag, returnSize);
        flag[0][x] = flag[1][y] = flag[2][d1] = flag[3][d2] = 0;
    }

    chessboard[x][y] = 0;
    backtrack(x, y+1, n, queen, chessboard, flag, returnSize);
}

int totalNQueens(int n) {
    int **chessboard = malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        chessboard[i] = calloc(n, sizeof(int));
    }

    int **flag = malloc(sizeof(int*)*4);
    for(int i=0; i<4; i++){
        flag[i] = calloc(2*n, sizeof(int));
    }

    int result=0;

    backtrack(0, 0, n, 0, chessboard, flag, &result);

    return result;
}

/*==============================================================*/
int main(){
    int answer = totalNQueens(8);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/