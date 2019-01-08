/*****************************************************************
Name    :LongestSubstring
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190102 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define DEBUG_LOG

/*==============================================================*/

/*==============================================================*/
int lengthOfLongestSubstring(char* s) {
    int solution = 0;
    //printf("Start Longest Substring : %s\n", s);
    char *head = s;
    char *anchor = s;

    while(*anchor && *head){
        //checking head and anchor
#ifdef DEBUG_LOG
        printf("Checking : ");
        putchar(*head);
        putchar(*anchor);
        printf("\n");
#endif
        char *current = head;
        int count = 0;
        while(current != anchor){
            if(*current == *anchor){
                head = current+1;
                //anchor = head;
                break;
            }
            count++;
            current++;
        }
        count++;
#ifdef DEBUG_LOG
        printf("Count : %d\n\n", count);
#endif
        if(count > solution)
            solution = count;
        anchor++;
    }
    
    return solution;
}

/*==============================================================*/
int main(){
    char *test_data = "dvdf";
    int answer;
    printf("Input String is : %s\n", test_data);

    answer = lengthOfLongestSubstring(test_data);
    printf("Answer : %d\n", answer);

    return 0;
}
/*==============================================================*/
