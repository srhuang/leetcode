/*****************************************************************
Name    :partition
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190403 Initial Version
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
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less_head = malloc(sizeof(struct ListNode));
    less_head->val=0;
    less_head->next=NULL;
    struct ListNode *less = less_head;

    struct ListNode *greater_head = malloc(sizeof(struct ListNode));
    greater_head->val=0;
    greater_head->next=NULL;
    struct ListNode *greater = greater_head;

    struct ListNode *current = head;
    while(current!=NULL){
        if(current->val < x){
            less->next = current;
            less = current;
        }else{
            greater->next = current;
            greater = current;
        }

        current = current->next;
    }

    //join the less to the greater
    less->next = greater_head->next;
    greater->next=NULL;

    return less_head->next;
}

/*==============================================================*/
int main(){
    int test[] = {1,4,3,2,5,2};
    int x = 3;
    int size = sizeof(test)/sizeof(int);
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = test[0];
    head->next = NULL;
    struct ListNode* pre=head;
    for(int i=1; i<size; i++){
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = test[i];
        temp->next = NULL;
        pre->next = temp;
        pre = temp;
    }

    struct ListNode *answer = partition(head, x);
    printf("Answer is : ");
    struct ListNode* current = answer;
    while(current != NULL){
        printf(" %d", current->val);
        current = current->next;
    }
    printf("\n");

    return 0;
}
/*==============================================================*/