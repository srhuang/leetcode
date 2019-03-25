/*****************************************************************
Name    :exist
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190325 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
bool recusive(char **board, int row, int col, int i, int j, char *word, int index)
{
    //no more to check
    if(index == strlen(word))
        return true;

    //check bording
    if(i<0 || j<0 || i>=row || j>= col)
        return false;

    //check equal
    if(board[i][j] != word[index])
        return false;

    //set zero for each visited element
    char temp = board[i][j];
    board[i][j] = 0;
    bool result = recusive(board, row, col, i-1, j, word, index+1) ||
        recusive(board, row, col, i, j+1, word, index+1) ||
        recusive(board, row, col, i+1, j, word, index+1) ||
        recusive(board, row, col, i, j-1, word, index+1);
    board[i][j] = temp;

    return result;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    for(int i=0; i<boardRowSize; i++){
        for(int j=0; j<boardColSize; j++){
            //printf("%c ", board[i][j]);
            if(recusive(board, boardRowSize, boardColSize, i, j, word, 0))
                return true;
        }
    }//for

    return false;
}

/*==============================================================*/
int main(){
    char test[3][4] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    int row = sizeof(test)/sizeof(test[0]);
    int col = sizeof(test[0])/sizeof(char);
    char **board = malloc(sizeof(char*)*row);
    for(int i=0; i<row; i++){
        board[i] = test[i];
    }
    char word[] = "ABCCEDF";

    bool answer = exist(board, row, col, word);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/