/*****************************************************************
Name    :merge
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190313 Initial Version
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
int compare(const void *arg1, const void *arg2)
{
    return ((*(const struct Interval*)arg1).start - (*(const struct Interval*)arg2).start);
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    printf("intervalsSize : %d\n", intervalsSize);

    if(intervalsSize == 0)
        return NULL;

    //sort by using start element
    qsort(intervals, intervalsSize, sizeof(struct Interval), compare);

    //handle the first interval
    struct Interval *result = malloc(sizeof(struct Interval));
    memcpy(&result[0], &intervals[0], sizeof(struct Interval));
    (*returnSize)++;

    for(int i=1; i<intervalsSize; i++){
        printf("interval %d = (%d, %d)\n", i, intervals[i].start, intervals[i].end);
        struct Interval *last = &result[(*returnSize)-1];
        if(intervals[i].start > last->end){
            //add new interval
            (*returnSize)++;
            result = realloc(result, sizeof(struct Interval) * (*returnSize));
            memcpy(&result[(*returnSize)-1], &intervals[i], sizeof(struct Interval));
        }else{
            //update the interval
            last->end = MAX(last->end, intervals[i].end);
        }
        
    }
    
    return result;
}

/*==============================================================*/
int main(){
    struct Interval intervals[] = {{2,6}, {8,10}, {15,18}, {1,3}};
    int returnSize = 0;

    struct Interval *answer = merge(intervals, sizeof(intervals)/sizeof(intervals[0]), &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("interval %d = (%d, %d)\n", i, answer[i].start, answer[i].end);
    }

    return 0;
}
/*==============================================================*/