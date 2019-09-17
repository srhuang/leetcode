/*****************************************************************
Name    :inorderTraversal
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190917 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root=NULL;

void insert(int data);

//Queue Node
typedef struct queueNode{
    struct TreeNode *data;
    struct queueNode *next;
}queueNode;

queueNode *front=NULL;
queueNode *rear=NULL;

int isEmpty();
void enqueue(struct TreeNode*); 
struct TreeNode* dequeue();

/*==============================================================*/
//Function area
/*==============================================================*/
//Queue operation
int isEmpty()
{
    return (front == NULL);
}

void enqueue(struct TreeNode *data)
{
    queueNode *new = (queueNode*)malloc(sizeof(queueNode));
    new->data = data;
    new->next = NULL;
    //push back
    if(rear == NULL){
        rear = new;
    }else{
        rear->next = new;
        rear = new;
    }

    if(front == NULL)
        front = new;
}

struct TreeNode* dequeue()
{
    if(isEmpty()){
        printf("Sequential Queue is Empty.\n");
        return NULL;
    }

    //pop front
    queueNode *temp = front;
    struct TreeNode *data = temp->data;
    front = temp->next;
    free(temp);
    return data;
}

//tree operation
void insert(int val){
    printf("Tree insert %d\n", val);
    struct TreeNode *new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    //Queue contain the tree node which is not complete.
    if(root == NULL){
        root = new;
    }else{
        //get from queue
        struct TreeNode *temp = front->data;
        printf("peek the front : %d\n", temp->val);

        if(temp->left == NULL){
            temp->left = new;
        }else{
            temp->right = new;
            dequeue();
        }
    }

    //enqueue the tree node
    enqueue(new);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
//recursive version
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL)
        return NULL;

    int *leftaddr = NULL;
    int *rightaddr = NULL;
    int leftsize = 0;
    int rightsize = 0;

    //left child
    if(root->left){
        leftaddr = inorderTraversal(root->left, &leftsize);
    }
    //right child
    if(root->right){
        rightaddr = inorderTraversal(root->right, &rightsize);
    }

    *returnSize = leftsize + rightsize + 1;
    int *result = malloc(sizeof(int) * (*returnSize));

    int index=0;
    for(int i=0; i<leftsize; i++){
        result[index++] = leftaddr[i];
    }
    free(leftaddr);

    result[index++] = root->val;

    for(int i=0; i<rightsize; i++){
        result[index++] = rightaddr[i];
    }
    free(rightaddr);

    return result;
}
*/

//iterative version
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL)
        return NULL;

    int *leftaddr = NULL;
    int *rightaddr = NULL;
    int leftsize = 0;
    int rightsize = 0;

    //left child
    if(root->left){
        leftaddr = inorderTraversal(root->left, &leftsize);
    }
    //right child
    if(root->right){
        rightaddr = inorderTraversal(root->right, &rightsize);
    }

    *returnSize = leftsize + rightsize + 1;
    int *result = malloc(sizeof(int) * (*returnSize));

    int index=0;
    for(int i=0; i<leftsize; i++){
        result[index++] = leftaddr[i];
    }
    free(leftaddr);

    result[index++] = root->val;

    for(int i=0; i<rightsize; i++){
        result[index++] = rightaddr[i];
    }
    free(rightaddr);

    return result;
}

/*==============================================================*/
int main(){
    int test[10]={0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(test)/sizeof(int);
    printf("size is : %d\n", size);

    for(int i=0; i<size; i++){
        insert(i);
    }

    int returnSize;
    printf("Inorder Traversal : ");
    int *answer = inorderTraversal(root, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}
/*==============================================================*/