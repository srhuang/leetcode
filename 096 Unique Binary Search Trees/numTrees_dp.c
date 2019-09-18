/*****************************************************************
Name    :numTrees_dp
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
int numTrees(int n){
    int ans[n+1];
    ans[0] = 1;
    ans[1] = 1;

    for(int i=2; i<=n; i++){
        ans[i] = 0;
        for(int j=1; j<=i; j++){
            ans[i] += ans[j-1] * ans[i-j];
        }
    }
    return ans[n];
}

/*==============================================================*/
int main(){
    int answer = numTrees(19);
    printf("Answer : %d\n", answer);
    return 0;
}
/*==============================================================*/