/*****************************************************************
Name    :AddTwoNumbers
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190102 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*==============================================================*/

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

/*==============================================================*/
ListNode* arrayCopy(int* array, int num){
    printf("Copy Array to linked list : ");
    printf("%d\t", array[0]);
    ListNode *head = malloc(sizeof(ListNode));
    head->val = array[0];
    head->next = NULL;

    ListNode *pre = head;
    for(int i=1; i<num; i++){
        printf("%d\t", array[i]);
        ListNode *current = malloc(sizeof(ListNode));
        pre->next = current;
        current->val = array[i];
        current->next = NULL;
        pre = current;
    }
    printf("\n");
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *input1 = l1;
    struct ListNode *input2 = l2;
    int data1;
    int data2;
    int carry=0;
    struct ListNode *pre;
    struct ListNode *solution = malloc(sizeof(struct ListNode));
    //do the first run
    if(input1 != NULL){
        data1 = input1->val;
        input1 = input1->next;
    }else{
        data1 = 0;
    }

    if(input2 != NULL){
        data2 = input2->val;
        input2 = input2->next;
    }else{
        data2 = 0;
    }
    solution->val = (data1+data2) % 10 + carry;
    //printf("%d\t", solution->val);
    carry = (data1+data2) / 10;
    solution->next = NULL;
    pre = solution;

    while((input1 != NULL) || (input2 != NULL) || (0 != carry)){
        struct ListNode *current = malloc(sizeof(struct ListNode));
        //get input value
        if(input1 != NULL){
            data1 = input1->val;
            input1 = input1->next;
        }else{
            data1 = 0;
        }

        if(input2 != NULL){
            data2 = input2->val;
            input2 = input2->next;
        }else{
            data2 = 0;
        }

        current->val = (data1+data2+carry) % 10;
        //printf("%d\t", current->val);
        carry = (data1+data2+carry) / 10;
        current->next = NULL;
        pre->next = current;
        pre = current;
    }

    return solution;
}

/*==============================================================*/
int main(){
    int test_data1[3] = {2, 4, 3};
    int test_data2[3] = {5, 6, 6};
    ListNode *test_data1_head = NULL;
    ListNode *test_data2_head = NULL;
    ListNode *answer = NULL;

    test_data1_head = arrayCopy(test_data1, sizeof(test_data1)/sizeof(int));
    test_data2_head = arrayCopy(test_data2, sizeof(test_data2)/sizeof(int));

    answer = addTwoNumbers(test_data1_head, test_data2_head);

    //print all linked list
    ListNode *temp = answer;
    while(NULL != temp){
        printf("%d\t", temp->val);
        temp = temp->next;
    }

    return 0;
}
/*==============================================================*/