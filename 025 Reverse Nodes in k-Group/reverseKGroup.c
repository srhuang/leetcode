/*****************************************************************
Name    :reverseKGroup
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190131 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

Node* arrayCopy(int* array, int num){
    printf("Copy Array to linked list : ");
    printf("%d\t", array[0]);
    Node *head = malloc(sizeof(Node));
    head->val = array[0];
    head->next = NULL;

    Node *pre = head;
    for(int i=1; i<num; i++){
        printf("%d\t", array[i]);
        Node *current = malloc(sizeof(Node));
        pre->next = current;
        current->val = array[i];
        current->next = NULL;
        pre = current;
    }
    printf("\n");

    return head;
}

/*==============================================================*/
//Function area
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head == NULL)
        return head;
    struct ListNode** stack = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);

    struct ListNode* current=head;
    for(int i=0; i<k; i++){
        if(current == NULL)
            return head;
        stack[i]=current;
        current = current->next;
    }
    struct ListNode* nextHead = current;

    struct ListNode* newHead = stack[k-1];
    current = newHead;
    for(int i=k-2; i>=0; i--){
        current->next = stack[i];
        current = stack[i];
    }
    //printf("last : %d\n", current->val);

    current->next = reverseKGroup(nextHead, k);

    free(stack);
    return newHead;
}

/*==============================================================*/
int main(){
    int test[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(test)/sizeof(int);

    Node *head = arrayCopy(test, size);
    Node *answer = reverseKGroup(head, 3);
    //traversal and print all linked list
    printf("Print all data in linked list : ");
    Node *temp = answer;
    while(NULL != temp){
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");


    return 0;
}
/*==============================================================*/