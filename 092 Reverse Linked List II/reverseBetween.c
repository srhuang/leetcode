/*****************************************************************
Name    :reverseBetween
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190422 Initial Version
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
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *current = head;
    struct ListNode *pre = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *con = NULL;

    if(head == NULL)
        return NULL;

    //locate the start point
    while(m>1){
        pre = current;
        current = current->next;
        m--;
        n--;
    }
    //printf("current : %d, pre : %d\n", current->val, pre->val);

    //assign the con and tail pointer
    con = pre;
    tail = current;

    //reverse the list
    struct ListNode *temp = NULL;
    while(n>0){
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
        n--;
    }
    //printf("current : %d, pre : %d\n", current->val, pre->val);

    //adjust the con
    if(con != NULL){
        con->next = pre;
    }else{
        head = pre;
    }
    tail->next = current;

    return head;
}

/*==============================================================*/
int main(){
    int test[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(test)/sizeof(int);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = test[0];
    head->next = NULL;
    struct ListNode *pre = head;
    for(int i=1; i<size; i++){
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = test[i];
        temp->next = NULL;
        pre->next = temp;
        pre = temp;
    }

    struct ListNode *answer = reverseBetween(head, 1, 6);

    return 0;
}
/*==============================================================*/