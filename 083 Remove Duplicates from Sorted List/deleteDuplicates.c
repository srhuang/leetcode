/*****************************************************************
Name    :deleteDuplicates
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190327 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area
struct ListNode {
    int val;
    struct ListNode *next;
};

/*==============================================================*/
//Function area
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return NULL;
    struct ListNode *pre=head;
    struct ListNode *current=pre->next;
    while(current!=NULL){
        printf("pre: %d\n", pre->val);
        while(current!=NULL && pre->val == current->val){
            current = current->next;
        }
        pre->next = current;
        pre = current;
        if(current!=NULL)
            current = current->next;
    }

    return head;
}

/*==============================================================*/
int main(){
    int test[] = {1,1,2,2,3,3,3};
    int size = sizeof(test)/sizeof(int);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = test[0];
    head->next = NULL;

    struct ListNode *pre = head;
    for(int i=1; i<size; i++){
        struct ListNode *current = malloc(sizeof(struct ListNode));
        current->val = test[i];
        current->next = NULL;
        pre->next = current;
        pre = current;
    }

    struct ListNode *answer = deleteDuplicates(head);
    pre = answer;
    printf("Answer is ");
    while(pre!=NULL){
        printf(" %d", pre->val);
        pre = pre->next;
    }

    return 0;
}
/*==============================================================*/