/*****************************************************************
Name    :isSameTree
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL && q==NULL)
        return true;

    if(p==NULL || q==NULL)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left, q->left)&& isSameTree(p->right, q->right); 
}

/*==============================================================*/
int main(){


    int answer = isSameTree();
    return 0;
}
/*==============================================================*/