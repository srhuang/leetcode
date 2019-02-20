/*****************************************************************
Name    :trap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190220 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MIN(a,b) (((a)<(b))?(a):(b)) 
#define MAX(a,b) (((a)>(b))?(a):(b))

/*==============================================================*/
//Function area
int trap(int* height, int heightSize) {
    if(0 == heightSize)
        return 0;
    
    int left_max[heightSize];
    int right_max[heightSize];
    int answer = 0;

    //fill up left max
    left_max[0] = height[0];
    for(int i=1; i<heightSize; i++){
        left_max[i] = MAX(height[i], left_max[i-1]);
    }

    //fill up right max
    right_max[heightSize-1] = height[heightSize-1];
    for(int i=heightSize-2; i>=0; i--){
        right_max[i] = MAX(height[i], right_max[i+1]);
    }

    //calculate each position
    for(int i=0; i<heightSize; i++){
        answer += MIN(left_max[i], right_max[i]) - height[i];
    }

    return answer;
}

/*==============================================================*/
int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height)/sizeof(int);
    printf("size is : %d\n", heightSize);

    int answer = trap(height, heightSize);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/