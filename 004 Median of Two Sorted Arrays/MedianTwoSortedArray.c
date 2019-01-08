/*****************************************************************
Name    :MedianTwoSortedArray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190102 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define DEBUG_LOG

/*==============================================================*/

/*==============================================================*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m; //size array 1
    int n; //size array 2

    double solution = 0.0;

    //array 1(m) should be smaller and array 2(n) should be larger
    if(nums1Size > nums2Size){
        int *tmp;
        tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        m = nums2Size;
        n = nums1Size;
    }else{
        m = nums1Size;
        n = nums2Size;
    }
    printf("size m : %d, size n : %d\n", m, n);
    int iMin = 0;
    int iMax = m;
    int halfLen = (m+n+1) / 2;

    while(iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        printf("Updating i and j : (%d, %d)\n", i, j);

        if((i<iMax) && (*(nums1 + i) < *(nums2 + j - 1))){ // i is too small
            printf("i is too small\n");
            iMin = i+1;
        }else if((i>iMin) && (*(nums1 + i - 1) > *(nums2 + j))){ // i is too big
            printf("i is too big\n");
            iMax = i-1;
        }else{ //i is perfect
            printf("i is perfect\n");
            //calculate max left
            int maxLeft = 0;
            if(0 == i){
                maxLeft = *(nums2 + j - 1);
            }else if(0 == j){
                maxLeft = *(nums1 + i - 1);
            }else{
                maxLeft = ((*(nums1 + i - 1)) > (*(nums2 + j - 1))) ? (*(nums1 + i - 1)) : (*(nums2 + j - 1));
            }
            printf("maxLeft : %d\n", maxLeft);
            if((m + n) % 2 == 1){
                return maxLeft;
            }

            //calculate min right
            int minRight = 0;
            if(i == m){
                minRight = *(nums2 + j);
            }else if(j == n){
                minRight = *(nums1 + i);
            }else{
                minRight = ((*(nums1 + i)) < (*(nums2 + j))) ? (*(nums1 + i)) : (*(nums2 + j));
            }
            printf("minRight : %d\n", minRight);
            return (maxLeft + minRight) / 2.0;
        }

    }//while

    return solution;
}

/*==============================================================*/
int main(){
    int test_data_1[7] = {1,3,4,5,6,7,8};
    int test_data_2[1] = {2};
    double answer = 0.0;

    printf("Input Test Data 1 :");
    for(int i=0; i<sizeof(test_data_1)/sizeof(int); i++){
        printf(" %d", test_data_1[i]);
    }
    printf("\n");

    printf("Input Test Data 2 :");
    for(int i=0; i<sizeof(test_data_2)/sizeof(int); i++){
        printf(" %d", test_data_2[i]);
    }
    printf("\n");

    answer = findMedianSortedArrays(test_data_1, sizeof(test_data_1)/sizeof(int),
        test_data_2, sizeof(test_data_2)/sizeof(int));

    printf("The answer is : %f", answer);

    return 0;
}
/*==============================================================*/