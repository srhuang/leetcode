/*****************************************************************
Name    :restoreIpAddresses
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190425 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char* s, int start, int col, char* ip, int ip_index, char ***result, int *returnSize)
{
    //printf("start:%d, col:%d, ip_index:%d\n", start, col, ip_index);
    //check index and col
    if(col > 4 || start > strlen(s))
        return;

    //valid ip, add to result
    if(col == 4 && start == strlen(s)){
        ip[ip_index]='\0';
        //printf("ip=%s\n", ip);
        (*returnSize)++;
        (*result) = realloc((*result), sizeof(char*)*(*returnSize));

        char *solution = malloc(sizeof(char)*(ip_index+1));
        //printf("ip_index : %d\n", ip_index);
        for(int i=0; i<=ip_index; i++){
            solution[i] = ip[i];
        }
        (*result)[(*returnSize)-1] = solution;
        return;
    }

    //
    for(int i=0; i<3; i++){
        if(start+i > strlen(s)){
            break;
        }
        //atoi
        int num = s[start]-'0';
        for(int j=1; j<=i; j++){
            num = num*10 + s[start+j]-'0';
        }
        //printf("num=%d\n", num);
        //check valid
        if(s[start] == '0' && i != 0)
            return;
        if(num<=255 && num>=0){
            int j=0;
            for(; j<=i; j++){
                ip[ip_index+j] = s[start+j];
            }
            if(col<3){
                ip[ip_index+(j++)] = '.';
                //printf("ip[]=%d\n", ip_index+j);
            }
            
            backtrack(s, start+i+1, col+1, ip, ip_index+j, result, returnSize);
        }
    }
    return;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    *returnSize = 0;
    char **result = malloc(sizeof(char*));
    char *ip = malloc(sizeof(char) * 18);

    backtrack(s, 0, 0, ip, 0, &result, returnSize);

    return result;
}



/*==============================================================*/
int main(){
    char test[] = "25525511135";
    int returnSize = 0;

    char **answer = restoreIpAddresses(test, &returnSize);
    //printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("answer : %s \n", answer[i]);
    }

    return 0;
}
/*==============================================================*/