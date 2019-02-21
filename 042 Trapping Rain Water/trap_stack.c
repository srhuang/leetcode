/*****************************************************************
Name    :trap_stack
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190220 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
#define MIN(a,b) (((a)<(b))?(a):(b)) 
#define MAX(a,b) (((a)>(b))?(a):(b))

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
int trap(int* height, int heightSize) {
    if(0 == heightSize)
        return 0;
    
    stack *trapStack = newStack(heightSize);

    int answer = 0;

    //calculate each position
    for(int i=0; i<heightSize; i++){
        while( (!isEmpty(trapStack)) && (height[i] > height[peek(trapStack)])){
            int top = pop(trapStack);

            if(isEmpty(trapStack))
                break;
            int distance = i-peek(trapStack)-1;
            int bound_height = MIN(height[i], height[peek(trapStack)]) - height[top];
            answer += (distance*bound_height);
            //printf("answer is :%d\n", answer);
        }
        push(i, trapStack);
    }

    deleteStack(trapStack);

    return answer;
}

/*==============================================================*/
int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height)/sizeof(int);
    printf("size is : %d\n", heightSize);

    int answer = trap(height, heightSize);
    printf("Answer is %d\n", answer);

    return 0;
}
/*==============================================================*/