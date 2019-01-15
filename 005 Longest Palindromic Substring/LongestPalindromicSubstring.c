/*****************************************************************
Name    :LongestPalindromicSubstring
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190102 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================*/
#define MIN(a,b) (((a)<(b))?(a):(b)) 
#define MAX(a,b) (((a)>(b))?(a):(b))

/*==============================================================*/
int expandAroundCenter(char *s, int left, int right){
    int L=left;
    int R=right;
    while(L>=0 && R<strlen(s) && s[L]==s[R]){
        L--;
        R++;
    }

    return R-L-1;
}

char* longestPalindrome(char* s) {
    printf("input string is : %s\n", s);
    printf("length : %zu\n", strlen(s));
    int start=0;
    int end=0;

    for(int i=0; i<strlen(s); i++){
        int len1=expandAroundCenter(s, i, i); //odd palindromic
        int len2=expandAroundCenter(s, i, i+1); //even palindromic
        int len=MAX(len1, len2);

        //update the longest substring
        if(len > end-start){
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    int answer_len=end-start+1;
    printf("start:%d, end:%d, len:%d\n", start, end, answer_len);

    char *answer=s+start;
    *(answer+answer_len) = '\0';
    return answer;
}

/*==============================================================*/
int main(){
    char test_data[1000]="asabbadfff";
    char *solution=longestPalindrome(test_data);
    printf("palindromic substring is : %s\n", solution);

    return 0;
}
/*==============================================================*/