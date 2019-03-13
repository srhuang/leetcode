/*****************************************************************
Name    :insert
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
struct Interval {
    int start;
    int end;
 };

/*==============================================================*/
//Function area
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX(a,b) ((a)>(b)?(a):(b))
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    //add new interval into sorted intervals
    int target=0;
    while(target<intervalsSize){
        if(intervals[target].start > newInterval.start)
            break;
        else
            target++;
    }
    struct Interval *newIntervals = malloc(sizeof(struct Interval) * (intervalsSize+1));
    int index=0;
    for(int i=0; i<intervalsSize+1; i++){
        if(i==target)
            newIntervals[i] = newInterval;
        else
            newIntervals[i] = intervals[index++];
    }
    /*
    for(int i=0; i<intervalsSize+1; i++){
        printf("index;%d, start:%d, end:%d\n", i, newIntervals[i].start, newIntervals[i].end);
    }*/

    //handle the first interval
    struct Interval *result = malloc(sizeof(struct Interval));
    memcpy(&result[0], &newIntervals[0], sizeof(struct Interval));
    (*returnSize)++;
    //compare each start
    for(int i=1; i<intervalsSize+1; i++){
        struct Interval *last = &result[(*returnSize)-1];
        if(newIntervals[i].start > last->end){
            //add new interval
            (*returnSize)++;
            result = realloc(result, sizeof(struct Interval)*(*returnSize));
            memcpy(&result[(*returnSize)-1], &newIntervals[i], sizeof(struct Interval));
        }else{
            last->end = MAX(last->end, newIntervals[i].end);
        }
    }

    free(newIntervals);
    newIntervals=NULL;

    return result;
}

/*==============================================================*/
int main(){
    struct Interval intervals[] = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    struct Interval newInterval={4,8};
    int returnSize = 0;

    struct Interval *answer = insert(intervals, sizeof(intervals)/sizeof(intervals[0]), newInterval, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("index:%d, (%d,%d)\n", i, answer[i].start, answer[i].end);
    }

    return 0;
}
/*==============================================================*/