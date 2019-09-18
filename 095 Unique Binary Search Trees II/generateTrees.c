/*****************************************************************
Name    :generateTrees
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

// Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}treeNode;



/*==============================================================*/
//Function area

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** genTree(int start, int end, int* returnSize){
    struct TreeNode** left;
    struct TreeNode** right;
    int left_size;
    int right_size;

    //printf("start:%d, end:%d\n", start, end);

    struct TreeNode** arr = malloc(sizeof(struct TreeNode*));

    if(start>end){
        struct TreeNode *root = NULL;
        (*returnSize)++;
        arr = realloc(arr, sizeof(struct TreeNode*)*(*returnSize));
        arr[*returnSize-1] = root;
        return arr;
    }

    if(start == end){
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root->val = start;
        root->left = NULL;
        root->right = NULL;

        (*returnSize)++;
        arr = realloc(arr, sizeof(struct TreeNode*)*(*returnSize));
        arr[*returnSize-1] = root;
        return arr;
    }

    //pick the root sequentially
    
    for(int i=start; i<=end; i++){
        //printf("root = %d\n", i);
        left_size=0;
        right_size=0;

        left = genTree(start, i-1, &left_size);
        right = genTree(i+1, end, &right_size);

        //get left and right list of tree root
        for(int l=0; l<left_size; l++){
            for(int r=0; r<right_size; r++){
                struct TreeNode *root = malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = left[l];
                root->right = right[r];
                
                (*returnSize)++;
                arr = realloc(arr, sizeof(struct TreeNode*)*(*returnSize));
                arr[*returnSize-1] = root;

            }
        }

        //free
        free(left);
        free(right);
    }
    return arr;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    *returnSize = 0;
    if(!n)
        return NULL;
    return genTree(1, n, returnSize);
}

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

/*==============================================================*/
int main(){
    int returnSize=0;

    struct TreeNode** answer = generateTrees(4, &returnSize);
    printf("returnSize : %d\n", returnSize);

    for(int i=0; i<returnSize; i++){
        //traverse and print the tree
        printf("Preorder Traversal : ");
        preorderTraversal(answer[i]);
        printf("\n");

        printf("Inorder Traversal : ");
        inorderTraversal(answer[i]);
        printf("\n");

        printf("Postorder Traversal : ");
        postorderTraversal(answer[i]);
        printf("\n");

    }

    return 0;
}
/*==============================================================*/