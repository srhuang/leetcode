/*****************************************************************
Name    :mergeTwoLists
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL && l2==NULL)
        return NULL;
    //handle the head
    struct ListNode *answer = (struct ListNode*)malloc(sizeof(struct ListNode));
    if((l2==NULL) || (l1!=NULL && l1->val < l2->val)){
        answer->val = l1->val;
        l1 = l1->next;
    }else{
        answer->val = l2->val;
        l2 = l2->next;
    }
    answer->next = NULL;

    struct ListNode *pre = answer;
    while((l1 != NULL) || (l2 != NULL)){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        if((l2==NULL) || (l1!=NULL && l1->val < l2->val)){
            temp->val = l1->val;
            l1 = l1->next;
        }else{
            temp->val = l2->val;
            l2 = l2->next;
        }
        temp->next = NULL;
        pre->next = temp;
        pre = temp;
        
    }//while

    return answer;
}

/*==============================================================*/
int main(){
    int test_data[3] = {1,2,4};
    int test_data2[3] = {1,3,6};

    Node *list1=arrayCopy(test_data, sizeof(test_data)/sizeof(int));
    Node *list2=arrayCopy(test_data2, sizeof(test_data2)/sizeof(int));

    Node *answer = mergeTwoLists(list1, list2);
    Node *temp = answer;
    while(NULL != temp){
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
/*==============================================================*/