/*****************************************************************
Name    :isScramble
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190403 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
bool recursion(char* s1, char* s2, int len) {
    if(0==strncmp(s1, s2, len))
        return true;

    //count the number of each character
    int count[256] = {0};
    for(int i=0; i<len; i++){
        //if(s1[i] == '\0' || s2[i] == '\0')
          //  return false;
        count[s1[i]]++;
        count[s2[i]]--;
    }

    //check the character count
    for(int i=0; i<256; i++){
        if(count[i]!=0)
            return false;
    }

    //try every cut line
    for(int i=1; i<len; i++){
        //s1 and s2; s1+i and s2+i
        if(recursion(s1, s2, i) && recursion(s1+i, s2+i, len-i)){
            return true;
        }

        //s1 and s2+(len-i); s1+i and s2
        if(recursion(s1, s2+(len-i), i) && recursion(s1+i, s2, len-i)){
            return true;
        }
    }//for

    return false;

}

bool isScramble(char* s1, char* s2) {
    int size = strlen(s1);
    return recursion(s1, s2, size);
}

/*==============================================================*/
int main(){
    char str1[] = "abb";
    char str2[] = "bba";

    bool answer = isScramble(str1, str2);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/