/*****************************************************************
Name    :isValid
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190125 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
#define MAXSTACK (10000)
int stack[MAXSTACK];
int stack_top=-1;
int isEmpty();
void push(int); 
int pop();

/*==============================================================*/
int isEmpty(){
    if(stack_top==-1){
        return 1; 
    }else{
        return 0;
    }
}

void push(int data){
    
    if(stack_top>=MAXSTACK){
        printf("Stack is FULL\n"); 
    }else{
        stack_top++;
        stack[stack_top]=data;
        //printf("push %d(%d)\n", data, stack_top);
    }
}

int pop(){
    int data;
    if(isEmpty()){
        printf("Stack is EMPTY\n");
        return -1;
    }else{
        data=stack[stack_top];
        stack_top--;
        //printf("pop %d(%d)\n", data, stack_top);
        return data; 
    }
}

int transforParentheses(char s){
    switch(s){
        case '(':
            return 1;
            break;
        case '[':
            return 2;
            break;
        case '{':
            return 3;
            break;
        case ')':
            return -1;
            break;
        case ']':
            return -2;
            break;
        case '}':
            return -3;
            break;
        default:
            return 0;
    }

    return 0;
}

bool isValid(char* s) {
    char *ptr = s;
    int size = strlen(s);

    for(int i=0; i<size; i++){
        //printf("%c ", *ptr);
        //printf("top:%d\t", stack_top);
        int data = transforParentheses(*ptr);
        if(data>0){
            //printf("push data : %d\n", data);
            push(data);
        }else if(data<0){
            int temp = pop();
            //printf("pop data : %d\n", temp);
            if(temp+data != 0){
                return false;
            }
        }else{
            printf("invalid symbol\n");
            return false;
        }

        ptr++;
    }
    
    //check empty
    if(!isEmpty())
        return false;

    return true;
}

/*==============================================================*/
int main(){
    char *test="{[]}";

    bool answer = isValid(test);
    printf("Answer is : %d\n", answer);

    return 0;
}
/*==============================================================*/