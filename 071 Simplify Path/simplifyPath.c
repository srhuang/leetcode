/*****************************************************************
Name    :simplifyPath
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190320 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
typedef struct stack{
    int size;
    char** container;
    int top;
}stack;

stack* newStack(int);
void doubleCapacity(stack *);
void deleteStack(stack*);
int isEmpty(stack*);
void push(char*, stack*); 
char* pop(stack*);
char* peek(stack*);
int size(stack*);

/*==============================================================*/
stack* newStack(int size)
{
    if(size<=0)
        return NULL;
    stack *ret = malloc(sizeof(stack));
    ret->size = size;
    ret->container = malloc(sizeof(char*) * size);
    ret->top = -1;

    return ret;
}

void deleteStack(stack *myStack){
    for(int i=0; i<myStack->size; i++){
        free(myStack->container[i]);
    }
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

void doubleCapacity(stack *myStack)
{
    myStack->size *= 2;
    myStack->container = (char**)realloc(myStack->container, sizeof(char*) * (myStack->size));
    //printf("\nDouble the capacity : %d.\n", myStack->size);
}

int size(stack *myStack)
{
    return myStack->top+1;
}

void push(char* data, stack *myStack){
    if(++myStack->top >= myStack->size){
        //printf("Stack is FULL\n"); 
        doubleCapacity(myStack);

    }
    //printf("top:%d, size:%d\n", myStack->top, myStack->size);
    char* temp = malloc(sizeof(char)*(strlen(data)+1));
    strcpy(temp, data);
    temp[strlen(data)]='\0';
    myStack->container[myStack->top]=temp;
    //printf("push : %s\n", myStack->container[myStack->top]);
}

char* pop(stack *myStack){
    char* data;
    if(isEmpty(myStack)){
        //printf("Stack is empty\n");
        return NULL;
    }else{
        data=myStack->container[myStack->top];
        myStack->top--;
        //printf("pop %d\n", data);
        return data; 
    }
}

char* peek(stack *myStack)
{
    char* data;
    if(isEmpty(myStack)){
        //printf("Stack is empty\n");
        return NULL;
    }else{
        data=myStack->container[myStack->top];
        return data; 
    }
}

/*==============================================================*/
//Function area
char* simplifyPath(char* path) {
    //new stack
    stack *myStack = newStack(5);
    //string token
    char *pch = strtok(path, "/");
    while(pch != NULL){
        //printf("%s ", pch);
        //handle the character
        if(0==strcmp(pch, ".")){
            //printf("nothing\n");
        }else if(0==strcmp(pch, "..")){
            //printf("pop\n");
            pop(myStack);
        }else{
            //printf("push\n");
            push(pch, myStack);
        }

        pch = strtok(NULL, "/");
    }//while

    char *result = malloc(sizeof(char)*1);
    result[0] = '\0';
    if(!isEmpty(myStack)){
        for(int i=0; i<=myStack->top; i++){
            char* temp = myStack->container[i];
            //printf("temp:%s\n", temp);
            int total_size = strlen(result)+1+strlen(temp)+1;
            result = realloc(result, sizeof(char)*(total_size));
            sprintf(result, "%s/%s", result, temp);
        }
    }else{
        result = realloc(result, sizeof(char)*2);
        result[0] = '/';
        result[1] = '\0';
    }
    
    //printf("%s\n", result);
    return result;
}

/*==============================================================*/
int main(){
    char test_data[] = "/xmtgE/./imKv/P///uDhoh/w/vWFR/kdJOi///tKI///k/NJ/zoUnW";

    char *answer = simplifyPath(test_data);
    printf("Answer is :%s\n", answer);

    return 0;
}
/*==============================================================*/