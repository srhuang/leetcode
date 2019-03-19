/*****************************************************************
Name    :isNumber
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190319 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
bool isNumber(char* s) {
    if(s==NULL)
        return false;

    int size = strlen(s);
    printf("string size is %d\n", size);
    if(0==size)
        return false;

    int index = 0;
    //skip whitespace
    while(s[index]==' '){
        index++;
    }
    printf("first non whitespace character : %c\n", s[index]);

    //handle significant
    if(s[index] == '+' || s[index] == '-'){
        index++;
    }

    //handle point and number
    int point_num = 0; //can only have one point
    int number_num = 0; //at least one number
    while(s[index] == '.' || (s[index] >='0'&&s[index]<='9')){
        s[index]=='.' ? point_num++ : number_num++;
        if(point_num > 1)
            return false;
        index++;
    }
    if(0==number_num)
        return false;
    printf("# of point:%d, # of number:%d\n", point_num, number_num);

    //handle exponent
    if(s[index] == 'e'){
        index++; //skip the 'e'
        //handle significant
        if(s[index] == '+' || s[index] == '-'){
            index++;
        }

        //handle only number
        number_num=0;
        while(s[index] >='0'&&s[index]<='9'){
            number_num++;
            index++;
        }
        if(0==number_num)
            return false;
    }

    //skip whitespace
    while(s[index]==' '){
        index++;
    }
    
    return (s[index]=='\0');
}

/*==============================================================*/
int main(){
    char test_data[] = "    -90e3   ";

    bool answer = isNumber(test_data);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/