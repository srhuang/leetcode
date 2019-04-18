/*****************************************************************
Name    :merge
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190411 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
void merge(int* nums1, int m, int* nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }

    //only handle the case that the rest number of nums2 is not zero
    while(j>=0){
        nums1[k--] = nums2[j--];
    }
}

/*==============================================================*/
int main(){
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};

    merge(nums1, 3, nums2, 3);
    int size = sizeof(nums1)/sizeof(int);
    printf("Answer is :");
    for(int i=0; i<size; i++){
        printf(" %d", nums1[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/