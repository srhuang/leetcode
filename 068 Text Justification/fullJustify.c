/*****************************************************************
Name    :fullJustify
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190319 Initial Version
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int index = 0;
    char **result = malloc(sizeof(char*));
    (*returnSize) = 0;

    while(index<wordsSize){
        //check each line max amount
        int amount = 0;
        int capacity = 0;
        //printf("before index : %d, amount : %d, capacity : %d\n", index, amount, capacity);
        while(index+amount < wordsSize){
            if((capacity+strlen(words[index+amount])) <= maxWidth-amount){ //assume one word one space
                capacity += strlen(words[index+amount]);
                amount++;
            }else{
                break;
            }
            
        }
        //printf("after index : %d, amount : %d, capacity : %d\n", index, amount, capacity);

        //prepare the result string
        (*returnSize)++;
        result = realloc(result, sizeof(char*) * (*returnSize));
        result[(*returnSize)-1] = malloc(sizeof(char) * (maxWidth+1));
        //handle the string
        char *result_ptr = result[(*returnSize)-1];
        //for the first word in line
        for(int i=0; i<strlen(words[index]); i++){
            *(result_ptr++) = words[index][i];
        }

        //for other words
        for(int i=1; i<amount; i++){
            //handle the whitespace
            int whitespace = 0;
            if(index+amount >= wordsSize){ // for the last line
                whitespace = 1;
            }else{
                whitespace = (maxWidth-capacity)/(amount-1) + (i<=(maxWidth-capacity)%(amount-1) ? 1:0);
            }
            printf("whitespace : %d\n", whitespace);
            for(int j=0; j<whitespace; j++){
                *(result_ptr++) = ' ';
            }

            //other words in line
            for(int j=0; j<strlen(words[index+i]); j++){
                *(result_ptr++) = words[index+i][j];
            }
        }
        while(result_ptr < result[(*returnSize)-1]+maxWidth){
            *(result_ptr++) = ' ';
        }
        *(result_ptr) = '\0';

        index += amount;
    }//while

    return result;
}

/*==============================================================*/
int main(){
    char *test_data[7] = {"This", "is", "an", "example", "of", "text", "justification."};
    int wordsSize = 7;
    int returnSize = 0;

    char **answer = fullJustify(test_data, wordsSize, 16, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%s\n", answer[i]);
    }

    return 0;
}
/*==============================================================*/