/*****************************************************************
Name    :REmatching
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190117 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
bool isMatch(char* s, char* p) {
    printf("Input String : %s\n", s);
    printf("RE String : %s\n", p);

    //set the terminal condition, s>p
    if(strlen(p)==0){
        printf("\tTerminal condition\n");
        return (strlen(s)==0);
    }

    //Check the first character
    bool firstMatch = (strlen(s)!=0 && 
        (*p==*s || *p=='.' ));

    //recursive call
    if(strlen(p)>=2 && *(p+1)=='*'){ //handle Kleene star
        printf("\tHandle Kleene Star\n");
        return (isMatch(s, p+2) ||  //for zero
            (firstMatch && isMatch(++s, p))); //for one match
    }else{
        printf("\tHandle Normal case\n");
        return firstMatch && isMatch(++s, ++p);
    }

}

/*==============================================================*/
int main(){
    char test_data[1000]="mississippi";
    char test_data2[1000]="mis*is*p*.";

    bool answer=isMatch(test_data, test_data2);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/