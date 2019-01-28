/*****************************************************************
Name    :mergeKLists
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190128 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

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
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    //for first head
    int min=INT_MAX;
    int min_index=-1;
    for(int i=0; i<listsSize; i++){
        if(lists[i]!=NULL && lists[i]->val < min){
            min = lists[i]->val;
            min_index = i;
        }
    }
    printf("min : %d, index : %d\n", min, min_index);
    if(min == INT_MAX || min_index== -1)
        return NULL;

    //New Node
    struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=min;
    head->next=NULL;
    lists[min_index] = lists[min_index]->next;

    struct ListNode *pre = head;
    while(1){
        int min=INT_MAX;
        int min_index=-1;
        for(int i=0; i<listsSize; i++){
            if(lists[i]!=NULL && lists[i]->val < min){
                min = lists[i]->val;
                min_index = i;
            }
        }
        printf("min : %d, index : %d\n", min, min_index);
        if(min == INT_MAX || min_index== -1)
            break;

        struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = min;
        temp->next = NULL;
        pre->next = temp;
        pre = temp;
        lists[min_index] = lists[min_index]->next;
    }//while

    return head;
}

/*==============================================================*/
int main(){
    int test_data[3] = {2,3,4};
    int test_data2[3] = {3,5,6};
    int test_data3[3] = {4,7,8};
    int listSize=3;

    Node *list1=arrayCopy(test_data, sizeof(test_data)/sizeof(int));
    Node *list2=arrayCopy(test_data2, sizeof(test_data2)/sizeof(int));
    Node *list3=arrayCopy(test_data3, sizeof(test_data3)/sizeof(int));

    Node **input=(Node**)malloc(sizeof(Node*)*listSize);
    input[0] = list1;
    input[1] = list2;
    input[2] = list3;
    Node *answer = mergeKLists(input, listSize);
    Node *temp = answer;
    while(NULL != temp){
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
/*==============================================================*/