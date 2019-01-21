/*****************************************************************
Name    :maxArea_twoPointer
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190118 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b)) 

/*==============================================================*/
int maxArea(int* height, int heightSize) {
    int max=0;
    int *front = height;
    int *end = &height[heightSize-1];
    int area;
    
    while(front<end){
        area=(end-front) * MIN(*front, *end);
        printf("%d\n", area);
        if(area>max)
            max=area;

        if(*front <= *end)
            front++;
        else
            end--;
    }

    return max;
}

/*==============================================================*/
int main(){
    int test_data[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(test_data)/sizeof(int);

    int answer=maxArea(test_data, size);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/