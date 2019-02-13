/*****************************************************************
Name    :longestValidParentheses
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190212 Initial Version
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

void push(int data, stack *myStack)
{
    if(myStack->top >= myStack->size){
        //printf("Stack is FULL\n"); 
    }else{
        myStack->top++;
        myStack->container[myStack->top]=data;
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
        return data; 
    }
}

int peek(stack *myStack)
{
    return myStack->container[myStack->top];
}

/*==============================================================*/
//Function area
int longestValidParentheses(char* s) {
    char *ptr = s;
    int size = strlen(s);
    int calculate=0;
    int max=0;

    if(0 == size)
        return 0;

    stack* myStack=newStack(size+1);

    push(-1, myStack);
    for(int i=0; i<size; i++){
        if(*ptr == '('){
            push(i, myStack);
        }else if(*ptr == ')'){
            pop(myStack);
            if(isEmpty(myStack)){
                push(i, myStack);
            }else{
                int length = i - peek(myStack);
                if(length > max)
                    max = length;
            }
        }
        ptr++;
    }

   
    deleteStack(myStack);

    return max;
}

/*==============================================================*/
int main(){
    char *test=")";

    int answer = longestValidParentheses(test);
    printf("\nAnswer is : %d\n", answer);

    return 0;
}
/*==============================================================*/