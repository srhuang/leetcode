/*****************************************************************
Name    :combinationSum
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190218 Initial Version
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
        //printf("push %d into stack\n", data);
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
        //printf("pop %d\n", data);
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
void DFS(int* candidates, int candidatesSize, int target, int** columnSizes, int *returnSize, 
    int ***result, stack *dfsStack)
{
    //terminal condition
    if(0 == target){
        int stackSize = size(dfsStack);
        printf("stack size is : %d\n", stackSize);
        
        //update array size
        (*returnSize)++;
        printf("return size : %d\n", (*returnSize));
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
    for(int i=0; i<candidatesSize; i++){
        //no need to check candidates which over target
        if(target < candidates[i]){
            break;
        }

        //Handle duplicate result, constraint on ascending order
        if(candidates[i] >= peek(dfsStack)){
            push(candidates[i], dfsStack);
            DFS(candidates, candidatesSize, target-candidates[i], columnSizes, returnSize, result, dfsStack);
            pop(dfsStack);
        }
    }

    return;
}

int compare(const void *arg1, const void *arg2) {
    return (*(const int *)arg1 - *(const int *)arg2);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int **result = malloc(sizeof(int*));
    *columnSizes = malloc(sizeof(int));
    stack *dfsStack = newStack(target/(candidates[0])+1);
    *returnSize = 0;
    DFS(candidates, candidatesSize, target, columnSizes, returnSize, &result, dfsStack);
    deleteStack(dfsStack);
    return result;
}

/*==============================================================*/
int main(){
    int candidates[]={2,3,6,7};
    int size = sizeof(candidates)/sizeof(int);
    printf("size is : %d\n", size);
    int returnSize=0;
    int **columnSizes = malloc(sizeof(int*));

    int **answer = combinationSum(candidates, size, 7, columnSizes, &returnSize);
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