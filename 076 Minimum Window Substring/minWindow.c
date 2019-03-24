/*****************************************************************
Name    :minWindow
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190322 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
char* minWindow(char* s, char* t) {
    int start = 0;
    int end = 0;
    int head = 0; //record the answer's head
    int map[128]={0}; //treat map as debt
    int counter = strlen(t);
    int min = INT_MAX;

    //initial the map
    for(int i=0; i<strlen(t); i++){
        map[t[i]]++;
    }

    //parsing all characters in string S
    while(end < strlen(s)){
        if(map[s[end++]]-->0){
            counter--;
        }

        //if window is valid, move on the start
        while(0==counter){
            //check update the min window
            if(end-start < min){
                min = end-start;
                head = start;
            }

            //try move on start
            if(0 == map[s[start++]]++){ //this character must in string t
                counter++;
            }
        }//while
    }//while

    if(min!=INT_MAX)
        s[head+min] = '\0';
    printf("min = %d, head = %d\n", min, head);

    return min==INT_MAX ? "" : &s[head];
}

/*==============================================================*/
int main(){
    char S[] = "a";
    char T[] = "aa";

    char *answer = minWindow(S, T);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/