/*****************************************************************
Name    :solveSudoku
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190214 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
bool checkSudoku(char** board, int row, int col, int val) {
    //check row
    for(int j=0; j<9; j++){
        int num = board[row][j]-'0';
        if(num == val) {
            //printf("check row fail\n");
            return false;
        }
    }

    //check col
    for(int i=0; i<9; i++){
        int num = board[i][col]-'0';
        if(num == val) {
            //printf("check col fail\n");
            return false;
        }
    }

    //check block
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int num = board[row/3*3+i][col/3*3+j]-'0';
            if(num == val) {
                //printf("check block fail\n");
                return false;
            }
        }
    }

    return true;
}

bool recursiveSudoku(char** board, int row, int col){
    //printf("row:%d, col:%d\n", row, col);
    //terminal condition
    if(row == 9){
        return true;
    } 
    if(col == 9){
        return recursiveSudoku(board, row+1, 0);
    }
    if(board[row][col] != '.'){
        return recursiveSudoku(board, row, col+1);
    }


    //sequential by row
    for(int c=1; c<=9; c++){
        //printf("Testing board[%d][%d]:c=%d\n", row, col, c);
        if(checkSudoku(board, row, col, c)){
            board[row][col] = c+'0';
            //printf("board[%d][%d]=%d\n", row, col, c);
            if(recursiveSudoku(board, row, col+1)){
                return true;
            }else{
                board[row][col] = '.';
            }
        }
    }//for

    return false;
}

void solveSudoku(char** board, int boardRowSize, int *boardColSizes) {

    if(!recursiveSudoku(board, 0, 0))
        printf("No solution\n");
    else
        printf("done\n");
}

/*==============================================================*/
int main(){
    int row=9;
    int col=9;
    char *test[9]={
        "53..7....", 
        "6..195...", 
        ".98....6.", 
        "8...6...3", 
        "4..8.3..1", 
        "7...2...6", 
        ".6....28.", 
        "...419..5", 
        "....8..79"};

    char **board = malloc(sizeof(char*)*row);
    for(int i=0; i<row; i++){
        char *each=malloc(sizeof(char)*col);
        board[i]=each;
    }

    //printf("Copy Input Sudoku : \n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            board[i][j] = test[i][j];
        }
        //printf("\n");
    }
    printf("Input Sudoku : \n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    solveSudoku(board, row, &col);

    printf("Output Sudoku : \n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*==============================================================*/