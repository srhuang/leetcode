/*****************************************************************
Name    :longestCommonPrefix
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190122 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return "";

    char *prefix = (char*)malloc(sizeof(char) * 1000);
    strcpy(prefix, strs[0]);
    char *prefix_head = prefix;
    printf("First String : %s\n", prefix);

    //for horizontal scanning
    for(int i=1; i<strsSize; i++){
        //parsing for each character
        char *ptr = strs[i];
        printf("Parsing string : %s\n", ptr);
        prefix = prefix_head;
        while(*ptr != 0){
            //printf("Parsing charachter : %c\n", *ptr);
            if(*prefix == *ptr){
                prefix++;
            }else{
                break;
            }
            ptr++;
        }
        *prefix = '\0';
        printf("\tprefix string : %s\n", prefix_head);
    }
    
    return prefix_head;
}

/*==============================================================*/
int main(){
    int strsSize = 3;

    char *test_data[3]={"aflower", "bflow", "cflight"}; 

    char *answer=longestCommonPrefix(test_data, strsSize);
    printf("Answer is %s\n", answer);

    return 0;
}
/*==============================================================*/
