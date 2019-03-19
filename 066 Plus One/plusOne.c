/*****************************************************************
Name    :plusOne
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190319 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    digits[digitsSize-1]++;

    int carry = 0;
    int i=digitsSize-1;
    while(i>=0){
        digits[i] += carry;
        carry =  digits[i]/10;
        digits[i] %= 10;
        i--;
        //printf(" %d", digits[i]);
    }

    //handle the last carry
    if(carry!=0){
        (*returnSize) = digitsSize+1;
    }else{
        (*returnSize) = digitsSize;
    }

    //prepare return int array
    int *result = malloc(sizeof(int) * (*returnSize));
    int index = 0;
    if(carry!=0){
        result[index++] = carry;
    }
    result[index++] = digits[0] % 10;
    for(int i=1; i<digitsSize; i++){
        result[index++] = digits[i];
    }

    return result;
}

/*==============================================================*/
int main(){
    int digits[]={9,9,9,9};
    int size = sizeof(digits)/sizeof(int);
    int returnSize = 0;

    int *answer = plusOne(digits, size, &returnSize);
    printf("return size is : %d\n", returnSize);
    printf("Answer is ");
    for(int i=0; i<returnSize; i++){
        printf("%d ", answer[i]);
    }

    return 0;
}
/*==============================================================*/