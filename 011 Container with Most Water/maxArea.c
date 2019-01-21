/*****************************************************************
Name    :maxArea
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

    for(int i=0; i<heightSize; i++){
        for(int j=i+1; j<heightSize; j++){
            printf("i=%d, j=%d\n", i, j);
            int width=j-i;
            int length=MIN(height[i], height[j]);
            int area=width*length;
            printf("width=%d, length=%d, area=%d\n", width, length, area);

            //get max area
            if(area>max)
                max=area;
        }
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