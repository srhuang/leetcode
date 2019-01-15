/*****************************************************************
Name    :Manacher's Algorithm
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190115 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============================================================*/
char* longestPalindrome(char* s) {
    int len = strlen(s);
    int manacher_len = len*2+1;
    printf("input string is : %s\n", s);
    printf("length : %d\n", len);
    printf("length of manacher : %d\n", manacher_len);

    //construct the manacher's array
    char manacher[manacher_len];
    for(int i=0; i<len; i++){
        manacher[i*2] = '#';
        manacher[i*2 + 1] = s[i];
    }
    manacher[manacher_len - 1]='#';
    printf("Manacher's string : ");
    for(int i=0; i<manacher_len; i++){
        printf("%c", manacher[i]);
    }
    printf("\n");

    //calculate the manacher's values
    int lps[manacher_len];
    int center=0;
    int right=0;
    int max_pos=0;
    lps[0]=0;
    for(int i=1; i<manacher_len; i++){
        //map position to get
        int map_pos=center-(i-center);
        if((map_pos>=0) && (i<right) && (i+lps[map_pos])<right){
            lps[i]=lps[map_pos];
        }else{ //check the character over right
            int j=i+1;
            while((j<manacher_len) && 
                (i-(j-i) > -1) && //check the left side
                (manacher[j]==manacher[i-(j-i)])){ 
                j++;
            }//j will points to first non-equal value
            //update the LPS value
            lps[i] = j-i-1;
            center=i;
            right=j-1;

            //update the max lps
            if(lps[i] > lps[max_pos]){
                max_pos=i;
            }//if
        }//else
    }//for
    printf("Manacher's values : ");
    for(int i=0; i<manacher_len; i++){
        printf("%d ", lps[i]);
    }
    printf("\n");
    printf("Max LPS is : s[%d]=%d\n", max_pos, lps[max_pos]);

    //prepare the output string
    int size=lps[max_pos];
    int start=(max_pos-size)/2;
    char *answer = malloc(sizeof(char) * (size+1));
    for(int i=0; i<size; i++){
        answer[i]=s[start+i];
    }
    answer[size]='\0';
    printf("Palindromic string is : %s\n", answer);

    return answer;
}

/*==============================================================*/
int main(){
    char test_data[1000]="babad";

    longestPalindrome(test_data);

    return 0;
}