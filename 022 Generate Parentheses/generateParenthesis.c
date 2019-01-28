/*****************************************************************
Name    :generateParenthesis
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190128 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** generateParenthesis(int n, int* returnSize) {
    char **answer = (char**)malloc(sizeof(char*) * (int)pow(2, 2*n));
    //terminal condition
    if(0 == n){
        char *each_answer = (char*)malloc(sizeof(char)*(2*n+1));
        sprintf(each_answer, "");
        answer[*returnSize] = each_answer;
        (*returnSize)=1;
        return answer;
    }

    if(1 == n){
        char *each_answer = (char*)malloc(sizeof(char)*(2*n+1));
        sprintf(each_answer, "()");
        answer[*returnSize] = each_answer;
        (*returnSize)=1;
        return answer;
    }

    //recusive
    for(int i=0; i<n; i++){
        //printf("i=%d\n", i);
        int inside_size=0;
        char **inside=generateParenthesis(i, &inside_size);
        //printf("inside size : %d\n", inside_size);

        int outside_size=0;
        char **outside=generateParenthesis(n-i-1, &outside_size);
        //printf("outside size : %d\n", outside_size);

        //for each ans
        for(int j=0; j<inside_size; j++){
            for(int k=0; k<outside_size; k++){
                //printf("(%s)%s", inside[j], outside[k]);
                char *each_answer = (char*)malloc(sizeof(char)*(2*n+1));
                sprintf(each_answer, "(%s)%s", inside[j], outside[k]);
                answer[*returnSize] = each_answer;
                (*returnSize)++;
            }
            
        }
    }//for

    return answer;
}

/*==============================================================*/
int main(){
    int input=5;
    int returnSize=0;

    char **answer = generateParenthesis(input, &returnSize);

    printf("Answer is : %d\n[\n", returnSize);
    for(int i=0; i<returnSize; i++){
        char *temp = answer[i];
        printf("\t%s\n", temp);
    }
    printf("]\n");

    return 0;
}
/*==============================================================*/