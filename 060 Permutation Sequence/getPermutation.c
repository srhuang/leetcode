/*****************************************************************
Name    :getPermutation
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
char* getPermutation(int n, int k) {
    char *result = malloc(sizeof(char)*(n+1));
    int factorial = 1;
    for(int i=1; i<=n; i++){
        factorial *= i;
        result[i-1] = '0'+i;
    }

    k--; //for using mod and div
    for(int i=0; i<n; i++){
        factorial /= (n-i); //calculate each sub group
        int index = (k/factorial) + i;

        //swap and shift the character
        char current = result[index];
        for(int j=index ;j>i; j--){
            result[j] = result[j-1];
        }
        result[i]=current;
        k %= factorial; // the next k
    }
    result[n]='\0';
    return result;
}

/*==============================================================*/
int main(){
    int n=3;

    char *answer = getPermutation(n, 5);
    printf("Answer is : %s\n", answer);

    return 0;
}
/*==============================================================*/