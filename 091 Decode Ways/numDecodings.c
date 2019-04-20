/*****************************************************************
Name    :numDecodings
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190419 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
int numDecodings(char* s) {
    //dynamic programming
    int size = strlen(s);
    if(0==size) return 0;

    int *dp = malloc(sizeof(int) * (size+1));

    //initialize the dp
    dp[0] = 1;
    dp[1] = s[0]=='0' ? 0:1;

    for(int i=2; i<=size; i++){
        dp[i]=0;
        if(s[i-1]!='0'){
            dp[i] += dp[i-1];
        }
        //index of string nust minus one
        if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')){
            dp[i] += dp[i-2];
        }
        //printf("dp[%d]=%d\n", i, dp[i]);
    }

    return dp[size];
}

/*==============================================================*/
int main(){
    char test[] = "101010";
    int answer = numDecodings(test);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/