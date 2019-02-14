/*****************************************************************
Name    :isValidSudoku
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
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int rowCount[9][9] = {0};
    int colCount[9][9] = {0};
    int block[3][3][9]={0};

    //check row
    for(int i=0; i<boardRowSize; i++){
        for(int j=0; j<boardColSize; j++){
            int num = board[i][j]-'1';
            if(num>=0){
                if(rowCount[i][num]++) 
                    return false;
                if(colCount[j][num]++)
                    return false;
                if(block[i/3][j/3][num]++)
                    return false;
            }
            
        }
    }

    return true;
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

    printf("Input Sudoku : \n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%c", test[i][j]);
        }
        printf("\n");
    }

    bool answer = isValidSudoku(test, row, col);
    printf("Answer is : %s\n", answer?"True":"False");

    return 0;
}
/*==============================================================*/