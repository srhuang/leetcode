/*****************************************************************
Name    :isMatch
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190222 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
int **memo;

/*==============================================================*/
bool dp(int i, int j, char* s, char* p){
    //check the memo for saving time
    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    bool ans;
    if(j == strlen(p)){ //parsing all pattern
        ans = (i==strlen(s)); //shoule not left any character
    }else{
        //check the first match
        bool firstMatch = (i<strlen(s)) &&
            (p[j] == s[i] || p[j] == '?');

        //recursive
        if(p[j] == '*'){ //handle Kleene star
            ans = (dp(i, j+1, s, p)) || //for empty string
                ((i<strlen(s)) && dp(i+1, j, s, p)); //for any sequence
        }else{
            ans = firstMatch && dp(i+1, j+1, s, p);
        }
    }

    memo[i][j] = ans;
    return ans;
}
//Function area
bool isMatch(char* s, char* p) {
    printf("Input String : %s\n", s);
    printf("RE String : %s\n", p);

    //malloc memo for dynamic programming
    memo = (int**)malloc(sizeof(int*) * (strlen(s)+1));
    for(int i=0; i<=strlen(s); i++){
        memo[i] = (int*)malloc(sizeof(int) * (strlen(p)+1));
    }

    //initialization value is -1
    for(int i=0; i<=strlen(s); i++){
        for(int j=0; j<=strlen(p); j++){
            memo[i][j] = -1;
        }
    }

    return dp(0, 0, s, p);

}

/*==============================================================*/
int main(){
    char test_data[] = "adceb";
    char pattern[] = "*a*b";

    bool answer = isMatch(test_data, pattern);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/