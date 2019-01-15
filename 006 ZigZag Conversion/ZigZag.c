/*****************************************************************
Name    :ZigZag
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190115 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================*/
char* convert(char* s, int numRows) {
    int len=strlen(s);
    if(NULL==s) return "";
    if(1==numRows) return s;
    //malloc numRows
    char *tail[numRows];
    char *ZigZag[numRows];
    for(int i=0; i<numRows; i++){
        tail[i]=malloc(sizeof(char) * len);
        ZigZag[i]=tail[i];
    }

    int mod=2*numRows-2;

    for(int i=0; i<len; i++){
        int z=i%mod;
        printf("i,z=(%d,%d)\n", i,z);

        //for pre z
        if(z<numRows){
            *(tail[z]++) = s[i];
        }else{
            *(tail[2*numRows-z-2]++)=s[i];
        }
    }

    //add end of string
    for(int i=0; i<numRows; i++){
        *tail[i]='\0';
    }

    //check the result
    for(int i=0; i<numRows; i++){
        printf("Array[%d]=%s\n", i, ZigZag[i]);
    }

    //copy the result
    char *answer=malloc(sizeof(char)*len+1);
    char *answer_tail=answer;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<strlen(ZigZag[i]); j++){
            *(answer_tail++)=ZigZag[i][j];
        }
    }
    *answer_tail='\0';

    return answer;
}

/*==============================================================*/
int main(){
    char test_data[1000]="PAYPALISHIRING";
    //char test_data[1000]="abcde";
    char *answer=convert(test_data, 3);
    printf("Answer is %s\n", answer);

    return 0;
}