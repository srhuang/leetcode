/*****************************************************************
Name    :letterCombinations
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190124 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*==============================================================*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char digitToalpha[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    if(*digits == 0){
        return NULL;
    }

    //parsing the first digits
    int digit = digits[0]-'0';
    char *alpha = digitToalpha[digit];
    int alphaSize = strlen(alpha);

    //printf("Digit is : %d\n", digit);
    //printf("Alpha is %s\n", alpha);
    //printf("Size of Alpha is %d\n", alphaSize);

    
    int answer_size=0;

    //terminal condition
    if(1 == strlen(digits)){
        char **answerOne = (char**)malloc(sizeof(char*) * alphaSize);
        for(int i=0; i<alphaSize; i++){
            answerOne[i] = (char*) malloc(sizeof(char) * 2);
            answerOne[i][0]=alpha[i];
            answerOne[i][1]='\0';
            //printf("one charater : %s\n", answerOne[i]);
            answer_size++;
        }
        (*returnSize)=answer_size;
        return answerOne;
    }

    //recursive
    char **substring = letterCombinations(digits+1, returnSize);
    char **answer = (char**)malloc(sizeof(char*) * (*returnSize) * alphaSize);
    
    for(int i=0; i<*returnSize; i++){
        for(int j=0; j<alphaSize; j++){
            
            char *string_concat = (char*)malloc(strlen(substring[i]) + 1);

            string_concat[0]=alpha[j];
            strcat(string_concat, substring[i]);

            //printf("string : %s\n", string_concat);

            answer[answer_size] = string_concat;
            answer_size++;
            
        }
    }
    //free(substring);
    //printf("Answer size is : %d\n", answer_size);
    (*returnSize)=answer_size;

    return answer;
    
}

/*==============================================================*/
int main(){
    //char test[3] = "72";
    int returnSize=0;

    char **answer = letterCombinations("754", &returnSize);
    printf("returnSize is %d\n", returnSize);


    printf("Answer : ");
    for(int i=0; i<returnSize; i++){
        printf("%s ", *answer);
        answer++;
    }
    printf("\n");

    return 0;
}
/*==============================================================*/