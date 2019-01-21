/*****************************************************************
Name    :romanToInt
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
int romanToInt(char* s) {
    int coin[] = {1,5,10,50,100,500,1000};
    char coin_name[7] = "IVXLCDM";
    int answer=0;

    printf("Input : %s\n", s);

    char *ptr = s;
    while(0!=*ptr){
        printf("Parsing : %c\n", *ptr);

        for(int i=0; i<sizeof(coin_name); i++){
            if(*ptr == coin_name[i]){
                printf("%d\n", coin[i]);
                if( (i+2 < sizeof(coin_name)) && 
                    ((*(ptr+1) == coin_name[i+1]) || (*(ptr+1) == coin_name[i+2]))){
                    printf("minus : %d\n", coin[i]);
                    answer -= coin[i];
                    printf("answer:%d\n", answer);
                }else{
                    printf("normal\n");
                    answer += coin[i];
                    printf("answer:%d\n", answer);
                }
                break;
            }
        }
        ptr++;
    }

    return answer;
}

/*==============================================================*/
int main(){
    char test_data[10]="LVIII";

    int answer=romanToInt(test_data);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/