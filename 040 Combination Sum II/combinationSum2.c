/*****************************************************************
Name    :combinationSum2
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190219 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
typedef struct stack{
    int size;
    int *container;
    int top;
}stack;

stack* newStack(int);
void deleteStack(stack*);
int isEmpty(stack*);
void push(int, stack*); 
int pop(stack*);
int peek(stack*);
int size(stack*);

/*==============================================================*/
stack* newStack(int size)
{
    if(size<=0)
        return NULL;
    stack *ret = malloc(sizeof(stack));
    ret->size = size;
    ret->container = malloc(sizeof(int) * size);
    ret->top = -1;

    return ret;
}

void deleteStack(stack *myStack){
    free(myStack->container);
    free(myStack);
}

int isEmpty(stack *myStack)
{
    if(myStack->top==-1){
        return 1; 
    }else{
        return 0;
    }
}

int size(stack *myStack)
{
    return myStack->top+1;
}

void push(int data, stack *myStack)
{
    if(myStack->top >= myStack->size){
        printf("Stack is FULL\n"); 
    }else{
        myStack->top++;
        myStack->container[myStack->top]=data;
        printf("push %d into stack\n", data);
    }
}

int pop(stack *myStack)
{
    int data;
    if(isEmpty(myStack)){
        //printf("Stack is empty\n");
        return -1;
    }else{
        data=myStack->container[myStack->top];
        myStack->top--;
        printf("pop %d\n", data);
        return data; 
    }
}

int peek(stack *myStack)
{
    int data;
    if(isEmpty(myStack)){
        //printf("Stack is empty\n");
        return -1;
    }else{
        data=myStack->container[myStack->top];
        return data; 
    }
}


/*==============================================================*/
//Function area
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void DFS(int* candidates, int candidatesSize, int start, int target, int** columnSizes, int *returnSize, 
    int ***result, stack *dfsStack)
{
    printf("start : %d, target:%d\n", start, target);

    //terminal condition
    if(0 == target){
        int stackSize = size(dfsStack);
        //printf("stack size is : %d\n", stackSize);
        
        //update array size
        (*returnSize)++;
        //printf("return size : %d\n", (*returnSize));
        *columnSizes = realloc(*columnSizes, sizeof(int)*(*returnSize));
        (*columnSizes)[(*returnSize)-1] = stackSize;

        //result array
        *result = realloc(*result, sizeof(int*)*(*returnSize));
        (*result)[*returnSize-1] = (int*)malloc(sizeof(int)*stackSize);

        //peek all stack
        printf("add new result : ");
        for(int i=0; i<stackSize; i++){
            (*result)[*returnSize-1][i] = dfsStack->container[i];
            printf("%d ", dfsStack->container[i]);
        }
        printf("\n");

        return;
    }

    //divide and conquer
    for(int i=start; i<candidatesSize; i++){
        printf("parsing : %d\n", candidates[i]);
        //no need to check candidates which over target
        if(target < candidates[i]){
            break;
        }

        //Handle duplicate result, constraint on ascending order
        if(candidates[i] >= peek(dfsStack)){
            push(candidates[i], dfsStack);
            if(i==start || candidates[i-1] != candidates[i]){
                DFS(candidates, candidatesSize, i+1, target-candidates[i], columnSizes, returnSize, result, dfsStack);
            }
            pop(dfsStack);
        }
    }

    return;
}

int compare(const void *arg1, const void *arg2)
{
    return (*(const int*)arg1 - *(const int*)arg2);
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    //prepare return data
    int **result = malloc(sizeof(int*));
    *columnSizes = malloc(sizeof(int));

    //sort candidates
    qsort(candidates, candidatesSize, sizeof(int), compare);
    //using stack to backtrace
    stack *dfsStack = newStack(candidatesSize+1);
    DFS(candidates, candidatesSize, 0, target, columnSizes, returnSize, &result, dfsStack);
    deleteStack(dfsStack);
    return result;
}

/*==============================================================*/
int main(){
    int candidates[] = {10,1,2,7,6,1,5};
    int candidatesSize = sizeof(candidates)/sizeof(int);
    printf("size is %d\n", candidatesSize);

    //prepare return data
    int returnSize = 0;
    int **columnSizes = malloc(sizeof(int*));

    int **answer = combinationSum2(candidates, candidatesSize, 8, columnSizes, &returnSize);
    printf("return size : %d\n", returnSize);
    printf("Answer is : \n");
    for(int i=0; i<returnSize; i++){
        printf("[");
        //printf("col  size : %d\n", (*columnSizes)[i]);
        for(int j=0; j<(*columnSizes)[i]; j++){
            printf("%d ", answer[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
/*==============================================================*/