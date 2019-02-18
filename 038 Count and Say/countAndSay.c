/*****************************************************************
Name    :countAndSay
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190218 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
char* countAndSay(int n) {
    //terminal condition
    if(1==n){
        char *result = malloc(sizeof(char)*2);
        result[0] = '1';
        result[1] = '\0';
        return result;
    }

    char *pre = countAndSay(n-1);
    int size = strlen(pre);
    char *answer = malloc(sizeof(char)*size*2+1);
    printf("size is : %d\n", size);
    char c = pre[0];
    int count = 1;
    int index = 0;
    for(int i=1; i<size; i++){
        if(pre[i] == c){
            count++;
        }else{
            answer[index++] = count+'0';
            answer[index++] = c;
            c=pre[i];
            count=1;
        }
    }
    answer[index++] = count+'0';
    answer[index++] = c;
    answer[index]='\0';
    free(pre);
    return answer;
}

/*==============================================================*/
int main(){

    char *answer = countAndSay(5);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/