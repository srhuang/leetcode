/*****************************************************************
Name    :strStr
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190205 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int strStr(char* haystack, char* needle) {

    if(*needle=='\0')
        return 0;
    if (*haystack == '\0')
        return -1;

    int i=0;
    while(*haystack != '\0'){
        char *pattern = needle;
        printf("parsing : (%c)\t", *haystack);
        char *start = haystack;
        while(*pattern != '\0'){
            printf("%c ", *pattern);
            if(*start != *pattern){
                break;
            }else{
                start++;
                pattern++;
            }
        }
        printf("\n");
        if(*pattern == '\0')
            return i;

        //next run
        haystack++;
        i++;
    }

    return -1;
}

/*==============================================================*/
int main(){
    char *haystack = "hello world";
    char *needle = "wo";

    int answer = strStr(haystack, needle);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/