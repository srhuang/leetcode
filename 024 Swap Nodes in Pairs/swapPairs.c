/*****************************************************************
Name    :swapPairs
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190128 Initial Version
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
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* pre = head;
    struct ListNode* current = head;
    struct ListNode* pair = head->next;
    head = pair;

    while(current!=NULL && pair!=NULL){
        if(pre != current){
            pre->next = pair;
        }
        struct ListNode* temp = pair->next;
        pair->next = current;
        current->next = temp;

        pre = current;
        current=temp;
        if(current != NULL)
            pair=current->next;
        else
            break;
    }

    return head;
}

/*==============================================================*/
int main(){
    int test[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(test)/sizeof(int);

    Node *head = arrayCopy(test, size);
    Node *answer = swapPairs(head);
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