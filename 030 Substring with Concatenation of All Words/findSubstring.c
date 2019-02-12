/*****************************************************************
Name    :findSubstring
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190205 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
typedef struct mapItem
{
    char* key;
    int val;
    int count;
    struct mapItem *next;
}mapItem;

typedef struct map
{
    mapItem *head;
    mapItem *end;
}map;

map* mapNew();
void mapClear(map* mapPtr);
mapItem* mapInsert(char *key, int val, map* mapPtr);
int mapErase(char *key, map* mapPtr);
mapItem* mapFind(char *key, map* mapPtr);

map* mapNew()
{
    map *newMap = malloc(sizeof(map));
    newMap->head = NULL;
    newMap->end = NULL;
    return newMap;
}

void mapClear(map* mapPtr)
{
    //free each item
    mapItem *parsing;
    parsing = mapPtr->head;
    while(parsing != NULL){
        //printf("%s %d\n", parsing->key, parsing->val);
        mapItem *temp = parsing;
        parsing = parsing->next;
        free(temp->key);
        temp->key=NULL;
        free(temp);
        temp=NULL;
    }

    //free map
    free(mapPtr);
    mapPtr=NULL;
}

mapItem* mapInsert(char *key, int val, map* mapPtr)
{
    mapItem *ret;
    //copy the new key
    char *newkey = malloc(sizeof(char) *(strlen(key)+1));
    strncpy(newkey, key, strlen(key)+1);

    //already exist
    mapItem *found = mapFind(key, mapPtr);
    if(found != NULL){
        //printf("add val : %s\n", key);
        found->val++;
        ret = found;
    }else{
        //printf("new item : %s\n", key);
        //new map item
        mapItem *newItem = malloc(sizeof(mapItem));
        newItem->key = newkey;
        newItem->val = val;
        newItem->count = 0;
        newItem->next= NULL;

        //add into map
        if (mapPtr->head == NULL){
            mapPtr->head = newItem;
            mapPtr->end = newItem;
        }else{
            mapPtr->end->next = newItem;
            mapPtr->end = newItem;
        }
        ret = newItem;
    }

    return ret;
}

int mapErase(char *key, map* mapPtr)
{
    mapItem *parsing = mapPtr->head;
    mapItem *pre = mapPtr->head;
    while(parsing != NULL){
        //printf("%s %d\n", parsing->key, parsing->val);
        if(strcmp(key, parsing->key) == 0){
            //delete
            if(parsing == mapPtr->head){
                mapPtr->head = parsing->next;
            }else{
                pre->next = parsing->next;
            }
            free(parsing);
            break;
        }
        pre = parsing;
        parsing = parsing->next;
    }

    if(parsing == NULL)
        return -1;
    else
        return 0;
}

mapItem* mapFind(char *key, map* mapPtr)
{
    mapItem *parsing = malloc(sizeof(mapItem));
    parsing = mapPtr->head;
    while(parsing != NULL){
        //printf("%s %d\n", parsing->key, parsing->val);
        if(strcmp(key, parsing->key) == 0){
            //printf("%s %d\n", parsing->key, parsing->val);
            break;
        }
        parsing = parsing->next;
    }

    return parsing;
}

void mapReset(map* mapPtr)
{
    mapItem *parsing = mapPtr->head;
    while(parsing != NULL){
        //printf("%s %d\n", parsing->key, parsing->val);
        parsing->count = 0;
        parsing = parsing->next;
    }
}

/*==============================================================*/
//Function area
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    //calculate the length
    int n = strlen(s);
    if(0 == n || 0 == wordsSize){
        return NULL;
    }

    int wordLen = strlen(words[0]);
    if(wordLen > n){
        return NULL;
    }

    //prepare the result
    int *result = malloc(sizeof(int) * (n - (wordLen * wordsSize)+1));
    *returnSize = 0;

    //construct the map of words
    map *wordMap = mapNew();
    for(int i=0; i<wordsSize; i++){
        mapInsert(words[i], 1, wordMap);
    }
    //printf("End of construct word map\n");

    //parsing the string
    //map *parsingMap = mapNew();
    char *window = malloc(sizeof(char) * wordLen + 1);
    for(int i=0; i < n - (wordLen * wordsSize)+1; i++){
        //printf("next iteration\n");
        
        int j=0;
        for(; j<wordsSize; j++){
            
            strncpy(window, s+i+j*wordLen, wordLen);
            window[wordLen] = '\0';
            //printf("window : %s\n", window);

            //check if find the word
            mapItem *word = mapFind(window, wordMap);
            if(word == NULL)
                break;

            //check the count
            word->count++;
            if(word->count > word->val)
                break;
        }
        mapReset(wordMap);
        
        if(j == wordsSize){
            //printf("result : %d\n", i);
            result[(*returnSize)++] = i;
        }
    }

    return result;
}

/*==============================================================*/
int main(){
    char test[] = "barfoothefoobarman";
    int wordsSize = 2;
    char *words[2] = {"foo","bar"};
    int returnSize;
    

    int *answer = findSubstring(test, words, wordsSize, &returnSize);

    printf("\nAnswer is \n");
    for(int i=0; i<returnSize; i++){
        printf("\tresult : %d\n", answer[i]);
    }

    return 0;
}
/*==============================================================*/