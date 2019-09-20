/*****************************************************************
Name    :recoverTree
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

//traversal
void preorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    printf("%d ", parent->val);
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void inorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    inorderTraversal(parent->left);
    printf("%d ", parent->val);
    inorderTraversal(parent->right);
}

void postorderTraversal(treeNode *parent)
{
    if(parent == NULL)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    printf("%d ", parent->val);
}

void inorder(treeNode *root, struct TreeNode** pre, 
    struct TreeNode** first, struct TreeNode** second)
{
    if(root == NULL)
        return;

    inorder(root->left, pre, first, second);

    //do inorder jobs
    if((*first==NULL) && (*pre!=NULL && (*pre)->val >= root->val)){
        *first = *pre;
        //printf("first : %d\n", first->val);
    }

    //using two if to prevent two error element are successive.
    if((*first!=NULL) && (*pre!=NULL && (*pre)->val >= root->val)){
        *second = root;
        //printf("second : %d\n", second->val);
    }

    *pre = root;

    inorder(root->right, pre, first, second);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode* pre = NULL;
    struct TreeNode* first = NULL; //first might be too large
    struct TreeNode* second = NULL; //second might be too less

    if(root == NULL)
        return;

    inorder(root, &pre, &first, &second);

    //swap two nodes
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}


/*==============================================================*/
int main(){
    int test[4]={5,6,2,1};
    int size = sizeof(test)/sizeof(int);
    //printf("size is : %d\n", size);

    for(int i=0; i<size; i++){
        insert(test[i]);
    }

    recoverTree(root);

    //traverse and print the tree
    printf("Preorder Traversal : ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal : ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorderTraversal(root);
    printf("\n");


    return 0;
}
/*==============================================================*/