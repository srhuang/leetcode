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
    //check row
    for(int i=0; i<boardRowSize; i++){
        int *count = calloc(boardColSize+1, sizeof(int));
        for(int j=0; j<boardColSize; j++){
            int num = board[i][j]-'0';
            if(num>=0 && num<=9){
                count[num]++;
                if(count[num]>1)
                    return false;
            }
            
        }
        free(count);
    }

    //check col
    for(int j=0; j<boardColSize; j++){
        int *count = calloc(boardRowSize+1, sizeof(int));
        for(int i=0; i<boardRowSize; i++){
            int num = board[i][j]-'0';
            if(num>=0 && num<=9){
                count[num]++;
                if(count[num]>1)
                    return false;
            }
            
        }
        free(count);
    }

    //check square
    for(int i=0; i<boardRowSize/3; i++){
        for(int j=0; j<boardColSize/3; j++){
            int *count = calloc(boardRowSize+1, sizeof(int));
            for(int m=0; m<3; m++){
                for(int n=0; n<3; n++){
                    int num = board[i*3+m][j*3+n]-'0';
                    if(num>=0 && num<=9){
                        count[num]++;
                        if(count[num]>1)
                            return false;
                    }
                }//for n
            }//for m
            free(count);
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