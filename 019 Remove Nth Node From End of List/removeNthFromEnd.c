/*****************************************************************
Name    :removeNthFromEnd
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190124 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* pre_N = head;
    struct ListNode* temp = head;
    int distance = n;

    while(NULL != temp){
        if(distance >= 0){
            distance--;
        }else{
            pre_N = pre_N->next;
            printf("pre Nth : %d\n", pre_N->val);
        }

        temp=temp->next;
    }//while

    //handle the removing
    //printf("distance:%d\n", distance);
    if(pre_N != NULL){
        if(distance<0){
            temp = pre_N->next;
            pre_N->next=temp->next;
            free(temp);
        }else{
            temp = pre_N;
            head = pre_N->next;
            free(temp);
        }
         
    }

    return head;
}

/*==============================================================*/
struct ListNode* arrayCopy(int* array, int num){
    printf("Copy Array to linked list : ");
    printf("%d\t", array[0]);
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = array[0];
    head->next = NULL;

    struct ListNode *pre = head;
    for(int i=1; i<num; i++){
        printf("%d\t", array[i]);
        struct ListNode *current = malloc(sizeof(struct ListNode));
        pre->next = current;
        current->val = array[i];
        current->next = NULL;
        pre = current;
    }
    printf("\n");

    return head;
}

int main(){
    //int test_data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int test_data[2]={1,2};
    struct ListNode *head = arrayCopy(test_data, sizeof(test_data)/sizeof(int));

    struct ListNode *answer = removeNthFromEnd(head, 2);

    //traversal and print all linked list
    printf("Print all data in linked list : ");
    struct ListNode *temp = answer;
    while(NULL != temp){
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    
    return 0;
}
/*==============================================================*/
