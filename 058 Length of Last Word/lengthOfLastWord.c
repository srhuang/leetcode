/*****************************************************************
Name    :lengthOfLastWord
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int lengthOfLastWord(char* s) {
    char *ptr = s;
    int count = 0;
    int result = count;

    while((*ptr)!='\0'){
        //printf("%c\n", *ptr);
        if((*ptr) == ' '){
            if(count != 0){
                result = count;
            }
            count=0;
        }else{
            count++;
        }
        
        ptr++;
    }
    if(count != 0){
        result = count;
    }

    return result;
}

/*==============================================================*/
int main(){
    char test_data[] = "hellow world";

    int answer = lengthOfLastWord(test_data);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/