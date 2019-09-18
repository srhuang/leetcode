/*****************************************************************
Name    :numTrees_recursive
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
int genTree(int start, int end){
    int left=0;
    int right=0;
    int num=0;

    //printf("start:%d, end:%d\n", start, end);

    if(start>=end){
        num++;
        return num;
    }

    //pick the root sequentially
    
    for(int i=start; i<=end; i++){
        //printf("root = %d\n", i);
        left = genTree(start, i-1);
        right = genTree(i+1, end);

        //get left and right list of tree root
        for(int l=0; l<left; l++){
            for(int r=0; r<right; r++){
                num++;
            }
        }
    }
    return num;
}

int numTrees(int n){
    return genTree(1, n);
}

/*==============================================================*/
int main(){
    int answer = numTrees(3);
    printf("Answer : %d\n", answer);
    return 0;
}
/*==============================================================*/