/*****************************************************************
Name    :multiply
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190221 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
char* multiply(char* num1, char* num2) {
    
    int len_nums1 = strlen(num1);
    int len_nums2 = strlen(num2);
    int len_answer = len_nums1 + len_nums2;
    int *answer = calloc(sizeof(int), len_answer);

    for(int j=len_nums2-1; j>=0; j--){
        for(int i=len_nums1-1; i>=0; i--){
            answer[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
        }
    }
    /*
    //check answer before carry
    printf("answer before carry : ");
    for(int i=0; i< len_answer; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    */

    //handle carry
    for(int i=len_answer-1; i>0; i--){
        answer[i-1] += answer[i]/10;
        answer[i] %= 10;
    }
    /*
    //check answer before carry
    printf("answer after carry : ");
    for(int i=0; i< len_answer; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
    */

    //transform to string
    char *result = malloc(sizeof(char) * (len_answer+1));
    int index=0;
    int i=0;
    while((index<len_answer) && (answer[index] == 0)){
        index++;
    }
    while(index<len_answer){
        result[i++] = answer[index++]+'0';
    }

    if(0==i)
        result[i++]='0';
    result[i]='\0';

    return result;
}

/*==============================================================*/
int main(){
    char num1[]="42345";
    char num2[]="0";

    char *answer = multiply(num1, num2);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/