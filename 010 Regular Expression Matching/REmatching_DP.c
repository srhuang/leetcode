/*****************************************************************
Name    :REmatching_DP
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190117 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
int **memo;
bool dp(int i, int j, char* s, char* p){
    if(memo[i][j] != -1)
        return memo[i][j];

    //no last character
    bool ans;
    if(j == strlen(p)){
        ans = (i==strlen(s));
    }else{
        //Check the first character
        bool firstMatch = (i<strlen(s) && 
            (p[j]==s[i] || p[j]=='.' ));

        //recursive call
        if(j+1<strlen(p) && p[j+1]=='*'){ //handle Kleene star
            
            ans = (dp(i, j+2, s, p) ||  //for zero
                (firstMatch && dp(i+1, j, s, p))); //for one match
            printf("\tHandle Kleene Star : %d\n", ans);
        }else{
            ans = firstMatch && dp(i+1, j+1, s, p);
            printf("\tHandle Normal case : %d\n", ans);
        }
    }
    memo[i][j] = ans;
    printf("write into (i, j)=(%d, %d) : %d\n", i, j, ans);
    return ans;
}

bool isMatch(char* s, char* p) {
    printf("Input String : %s\n", s);
    printf("RE String : %s\n", p);

    //malloc memo
    memo = (int**)malloc(sizeof(int*) * (strlen(s)+1));
    for(int i=0; i<=strlen(s); i++){
        memo[i] = (int*)malloc(sizeof(int) * (strlen(p)+1));
    }

    //initialization
    for(int i=0; i<=strlen(s); i++){
        for(int j=0; j<=strlen(p); j++){
            memo[i][j] = -1;
        }
    }

    return dp(0, 0, s, p);
}

/*==============================================================*/
int main(){
    char test_data[1000]="missssippi";
    char test_data2[1000]="mis*i*p*.";

    bool answer=isMatch(test_data, test_data2);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/