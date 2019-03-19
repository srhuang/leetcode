/*****************************************************************
Name    :addBinary
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
char* addBinary(char* a, char* b) {
    int a_size = strlen(a);
    int b_size = strlen(b);
    int max_size = a_size>b_size ? a_size : b_size;

    int carry = 0;
    int i=a_size-1;
    int j=b_size-1;
    int k=max_size-1;

    char *result = malloc(sizeof(char) * (max_size+1));
    result[max_size]='\0';
    while(i>=0 || j>=0){
        carry += i>=0 ? a[i--]-'0' : 0;
        carry += j>=0 ? b[j--]-'0' : 0;
        result[k--]=carry%2 + '0';
        carry /= 2;
    }
    //printf("result:%s\n", result);

    //handle carry
    //printf("carry:%d\n", carry);
    if(carry!=0){
        result = realloc(result, sizeof(char) * (max_size+2));
        for(int i=max_size+1; i>0; i--){
            result[i]=result[i-1];
        }
        result[0] = carry+'0';
    }
    //printf("result:%s\n", result);

    return result;
}

/*==============================================================*/
int main(){
    char test_data1[] = "1010";
    char test_data2[] = "1011";

    char *answer = addBinary(test_data1, test_data2);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/