/*****************************************************************
Name    :rotateRight
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190314 Initial Version
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

struct ListNode *arrayToLinkedList(int *array, int num)
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = array[0];
    head->next = NULL;

    struct ListNode *pre=head;
    for(int i=1; i<num; i++){
        struct ListNode *current = malloc(sizeof(struct ListNode));
        current->val = array[i];
        current->next = NULL;
        pre->next = current;
        pre = current;
    }

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
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL)
        return NULL;
    if(0==k)
        return head;

    //make it circular
    int num = 1;
    struct ListNode *current = head;
    while(current->next != NULL){
        current = current->next;
        num++;
    }
    printf("num is %d\n", num);
    current->next = head;

    //find the new head
    current = head;
    k %= num;
    k = num-k;
    int count=1;
    while(count < k){
        current = current->next;
        count++;
    }
    printf("last Node is %d\n", current->val);
    struct ListNode *result = current->next;
    current->next=NULL;

    return result;
}

/*==============================================================*/
int main(){
    int test_data[] = {0,1};
    struct ListNode *head = arrayToLinkedList(test_data, sizeof(test_data)/sizeof(int));

    struct ListNode *answer = rotateRight(head, 1);
    printf("Answer is ");
    struct ListNode *current = answer;
    while(current!=NULL){
        printf("%d ", current->val);
        current = current->next;
    }

    return 0;
}
/*==============================================================*/