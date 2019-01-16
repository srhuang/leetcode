/*****************************************************************
Name    :PalindromeNumber
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190116 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*==============================================================*/
bool isPalindrome(int x) {
    printf("Input int : %d\n", x);
    if(x<0)
        return false;
    if(x%10 == 0 && x!=0)
        return false;

    //reverse the number
    int reverse=0;
    while(x > reverse){
        reverse = reverse*10 + x%10;
        x /= 10;
    }
    printf("x=%d, reverse number : %d\n", x, reverse);

    return (x==reverse) || (x==reverse/10);
}

/*==============================================================*/
int main(){
    int test_data=10;
    //char test_data[1000]="abcde";
    bool answer=isPalindrome(test_data);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/