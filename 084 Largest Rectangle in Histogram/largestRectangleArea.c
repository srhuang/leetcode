/*****************************************************************
Name    :largestRectangleArea
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190328 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MAX(a,b) ((a)>(b)?(a):(b))

/*==============================================================*/
//Function area
int largestRectangleArea(int* heights, int heightsSize) {
    if(0==heightsSize)
        return 0;
    int *leftLower = malloc(sizeof(int) * heightsSize);
    int *rightLower = malloc(sizeof(int) * heightsSize);
    leftLower[0] = -1;
    rightLower[heightsSize-1] = heightsSize;

    //calculate the left Lower
    for(int i=1; i<=heightsSize-1; i++){
        int index = i-1;
        while(index>=0 && heights[index]>=heights[i]){
            index = leftLower[index];
        }
        leftLower[i] = index;
    }

    //calculate the right Lower
    for(int i=heightsSize-2; i>=0; i--){
        int index=i+1;
        while(index<=heightsSize-1 && heights[index]>=heights[i]){
            index = rightLower[index];
        }
        rightLower[i] = index;
    }

    //calculate max area by leftLower and rightLower
    int max_area = 0;
    for(int i=0; i<=heightsSize-1; i++){
        max_area = MAX(max_area, heights[i]*(rightLower[i]-leftLower[i]-1));
    }

    return max_area;
}

/*==============================================================*/
int main(){
    int heights[]= {2,1,5,6,2,3};
    int size = sizeof(heights)/sizeof(int);

    int answer = largestRectangleArea(heights, size);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/