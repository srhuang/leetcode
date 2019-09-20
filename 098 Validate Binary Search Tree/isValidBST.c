/*****************************************************************
Name    :isValidBST
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190920 Initial Version
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*==============================================================*/
//Global area

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 }treeNode;
 
treeNode *root=NULL;

void insert(int data);

//Queue Node
typedef struct queueNode{
    treeNode *data;
    struct queueNode *next;
}queueNode;

queueNode *front=NULL;
queueNode *rear=NULL;

int isEmpty();
void enqueue(treeNode*); 
treeNode* dequeue();

/*==============================================================*/
//Function area
//Queue operation
int isEmpty()
{
    return (front == NULL);
}

void enqueue(treeNode *data)
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

treeNode* dequeue()
{
    if(isEmpty()){
        //printf("Sequential Queue is Empty.\n");
        return NULL;
    }

    //pop front
    queueNode *temp = front;
    treeNode *data = temp->data;
    front = temp->next;
    free(temp);
    return data;
}

//tree operation
void insert(int val){
    //printf("Tree insert %d\n", val);
    treeNode *new = (treeNode*)malloc(sizeof(treeNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    //Queue contain the tree node which is not complete.
    if(root == NULL){
        root = new;
    }else{
        //get from queue
        treeNode *temp = front->data;
        //printf("peek the front : %d\n", temp->val);

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

bool recursive(struct TreeNode* root, struct TreeNode* lower, struct TreeNode* upper)
{
    if(root == NULL)
        return true;

    if((lower && root->val <= lower->val) || (upper && root->val >= upper->val))
        return false;

    return recursive(root->left, lower, root) && recursive(root->right, root, upper);
}

bool isValidBST(struct TreeNode* root){
    return recursive(root, NULL, NULL);
}


/*==============================================================*/
int main(){
    int test[4]={5,4,2,6};
    int size = sizeof(test)/sizeof(int);
    //printf("size is : %d\n", size);

    for(int i=0; i<size; i++){
        insert(test[i]);
    }

    bool answer = isValidBST(root);
    printf("answer is %s\n", answer?"True":"False");

    return 0;
}
/*==============================================================*/