/*****************************************************************
Name    :StringToInteger
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190115 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/*==============================================================*/
int myAtoi(char* str) {
    printf("Input string : %s\n", str);

    //remove space
    while(*str == ' ')
    {
        str++;
    }
    printf("After Remove prefix Space : %s\n", str);

    //check the first character
    char *iterator=str;
    int sign=1;
    if((*iterator == '-') || (*iterator == '+')){
        if(*iterator == '-')
            sign=-1;
        printf("is sign : %d\n", sign);
        iterator++;
    }else if(isdigit(*iterator)){
        printf("is digit\n");
    }else{
        return 0;
    }

    //parsing the digit
    int answer=0;
    while((*iterator != 0) && (isdigit(*iterator))){
        printf("parsing : %c\n", *iterator);

        //check overflow
        if(answer>INT_MAX/10){
            printf("INT overflow\n");
            if(-1 ==sign)
                return INT_MIN;
            else
                return INT_MAX;
        }
        answer *= 10;

        //check overflow
        if(answer>INT_MAX-(*iterator-'0')){
            if(-1 ==sign)
                return INT_MIN;
            else
                return INT_MAX;
        }
        answer += *iterator-'0';
        iterator++;
    }

    //Handle the sign
    if(-1 == sign){
        //check underflow
        if(INT_MIN+answer>0){
            return INT_MIN;
        }
        answer = 0-answer;
    }
    return answer;
}

/*==============================================================*/
int main(){
    char test_data[1000]=" -42";
    //char test_data[1000]="abcde";
    int answer=myAtoi(test_data);
    printf("Answer is %d\n", answer);

    return 0;
}