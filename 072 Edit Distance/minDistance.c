/*****************************************************************
Name    :minDistance
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190322 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MIN(a,b) ((a)<(b)?(a):(b))

/*==============================================================*/
//Function area
int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int **dp = malloc(sizeof(int*)*(m+1));
    for(int i=0; i<=m; i++){
        dp[i] = malloc(sizeof(int)*(n+1));
    }

    //dynamic programming
    dp[0][0] = 0;
    for(int j=1; j<=n; j++){
        dp[0][j] = j;
    }
    for(int i=1; i<=m; i++){
        dp[i][0] = i;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = MIN(MIN(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }//for
    /*
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */

    return dp[m][n];
}

/*==============================================================*/
int main(){
    char word1[] = "intention";
    char word2[] = "execution";

    int answer = minDistance(word1, word2);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/