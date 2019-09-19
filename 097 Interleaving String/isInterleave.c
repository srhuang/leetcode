/*****************************************************************
Name    :isInterleave
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190918 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
bool isInterleave(char * s1, char * s2, char * s3){
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int s3_len = strlen(s3);
    if(s1_len + s2_len != s3_len)
        return false;

    //dp table
    bool **dp = malloc(sizeof(bool*)*(s1_len+1));
    for(int i=0; i<=strlen(s1); i++){
        dp[i] = malloc(sizeof(bool) * (s2_len+1));
    }

    for(int i=0; i<=s1_len; i++){
        for(int j=0; j<=s2_len; j++){
            //first element
            if(0==i && 0==j){
                dp[i][j] = true;
            }else if(0==i){ //first row
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
            }else if(0==j){ //forst col
                dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
            }else{
                dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) ||
                    (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
            }
        }
    }

    return dp[s1_len][s2_len]; 
}


/*==============================================================*/
int main(){
    char *s1 = "aabcc";
    char *s2 = "dbbca";
    char *s3 = "aadbbcbcac";

    bool answer = isInterleave(s1, s2 ,s3);
    printf("answer is : %s\n", answer?"true":"false");

    return 0;
}
/*==============================================================*/