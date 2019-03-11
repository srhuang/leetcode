/*****************************************************************
Name    :groupAnagrams
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190311 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
void quicksort(char** strs, char** hash, int left, int right)
{
    if(left >= right)
        return;

    char* pivot = hash[(left+right)/2];
    int i=left-1;
    int j=right+1;
    while(i<j){ //break if i==j
        do{
            i++;
        }while(strncmp(hash[i], pivot, 26*2+1)<0);

        do{
            j--;
        }while(strncmp(pivot, hash[j], 26*2+1)<0);

        if(i<j){
            //swap hash
            char* temp = hash[i];
            hash[i] = hash[j];
            hash[j] = temp;

            //swap strs
            temp = strs[i];
            strs[i] = strs[j];
            strs[j] = temp;
        }
    }//while

    quicksort(strs, hash, left, i-1);
    quicksort(strs, hash, j+1, right);
}

/*==============================================================*/
//Function area
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    //prepare the hash table
    char **hash = malloc(sizeof(char*)*strsSize);
    for(int i=0; i<strsSize; i++){
        hash[i] = malloc(sizeof(char)*(26*2+1));
    }

    //construct the hash string
    for(int i=0; i<strsSize; i++){
        int count[26]={0};
        int size = strlen(strs[i]);
        for(int j=0; j<size; j++){
            count[strs[i][j]-'a']++;
        }
        //output all count to hash
        int index=0;
        for(int k=0; k<26; k++){
            //printf("#%d", count[k]);
            hash[i][index++]='#';
            hash[i][index++]=count[k]+'0';
        }
        hash[i][index]='\0';
        printf("hash[%d]=%s\n", i, hash[i]);
    }

    //qick sort
    quicksort(strs, hash, 0, strsSize-1);
    printf("After sort...\n");
    for(int i=0; i<strsSize; i++){
        printf("hash[%d]=%s\n", i, hash[i]);
    }

    //calculate the result by hash table
    *returnSize = 1;
    char ***result = malloc(sizeof(char**));
    result[0] = malloc(sizeof(char*));
    *columnSizes = malloc(sizeof(int));

    result[0][0] = strs[0];
    (*columnSizes)[0] = 1;
    
    for(int i=1; i<strsSize; i++){
        if(0 != strncmp(hash[i], hash[i-1], 26*2+1)){
            //need to add new group
            (*returnSize)++;
            result = realloc(result, sizeof(char**) * (*returnSize));
            result[(*returnSize)-1] = malloc(sizeof(char*));
            *columnSizes = realloc(*columnSizes, sizeof(int)*(*returnSize));
            (*columnSizes)[(*returnSize)-1] = 0;
        }
        //returnSize point to the right group to add
        (*columnSizes)[(*returnSize)-1]++;
        int col_size = (*columnSizes)[(*returnSize)-1];
        
        result[(*returnSize)-1] = realloc(result[(*returnSize)-1], sizeof(char*)*col_size);
        result[(*returnSize)-1][col_size-1] = strs[i];
    }
    return result;
}

/*==============================================================*/
int main(){
    char *test_data[6]={
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    int returnSize = 0;
    int **columnSizes=malloc(sizeof(int*));

    char ***answer = groupAnagrams(test_data, 6, columnSizes, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("columnSizes : %d\n", (*columnSizes)[i]);
        
        for(int j=0; j<(*columnSizes)[i]; j++){
            printf(" %s", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*==============================================================*/