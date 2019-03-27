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

    //new temp head
    struct ListNode *tempHead = malloc(sizeof(struct ListNode));
    tempHead->val = 0;
    tempHead->next = head;
    
    struct ListNode *pre = tempHead;
    struct ListNode *current = tempHead->next;
    while(current!=NULL){
        printf(" %d", pre->val);
        while(current->next!=NULL && current->val == current->next->val){
            current = current->next;
        }
        if(current == pre->next){
            pre = pre->next;
        }else{
            pre->next = current->next;
        }
        current = current->next;
        printf(" %d", pre->val);
    }//while
    printf("\n");

    return tempHead->next;
}

/*==============================================================*/
int main(){
    int test[] = {1,1,1,2,3,3,3,4,4,5};
    int size = sizeof(test)/sizeof(int);

    //for head
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
    pre=answer;
    printf("Answer is :");
    while(pre!=NULL){
        printf(" %d", pre->val);
        pre = pre->next;
    }

    return 0;
}
/*==============================================================*/