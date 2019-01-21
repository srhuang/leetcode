/*****************************************************************
Name    :intToRoman
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190121 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
char* intToRoman(int num) {
    int coin[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int coin_size = sizeof(coin)/sizeof(int);
    char coin_name[13][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    char *answer = (char*)malloc(sizeof(char) * 20);
    char *answer_ptr = answer;

    //using recursive
    int remain = num;
    for(int i=coin_size-1; i>=0; i--){
        int coin_value = coin[i];
        //printf("coin : %d\n", coin_value);

        while(remain>=coin_value){
            printf("pick up the coin : %s(%zu)\n", coin_name[i], strlen(coin_name[i]));
            if(2 == strlen(coin_name[i])){
                printf("2 element\n");
                *answer_ptr++=coin_name[i][0];
                *answer_ptr++=coin_name[i][1];
            }else{
                printf("one element\n");
                *answer_ptr++=*coin_name[i];
            }
            
            remain -= coin_value;
        }
    }
    *answer_ptr='\0';

    return answer;
}

/*==============================================================*/
int main(){
    int test_data=1994;

    char *answer=intToRoman(test_data);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/