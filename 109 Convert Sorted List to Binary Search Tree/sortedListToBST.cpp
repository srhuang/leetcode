/*****************************************************************
Name    :sortedListToBST
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191009 Initial Version
*****************************************************************/
#include <iostream>
using namespace std;

/*==============================================================*/
//Global area
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(-1), left(NULL), right(NULL){};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

/*==============================================================*/
//Function area
class LinkedList{
public:
    ListNode *head;
    LinkedList(const int *input, int size);
    void display();
};

LinkedList::LinkedList(const int *input, int size)
{
    head = NULL;
    ListNode *current;
    for(int i=0; i<size; i++){
        ListNode *newNode = new ListNode(input[i]);
        if(NULL == head){
            head = newNode;
            current = head;
        }else{
            current->next = newNode;
            current = current->next;
        }
    }
}

void LinkedList::display()
{
    if(NULL == head){
        return;
    }

    ListNode *current = head;
    while(current != NULL){
        cout << " " << current->val;
        current = current->next;
    }
    cout <<endl;
}

class BinaryTree{
public:
    TreeNode *root;
    void preorderTraversal(TreeNode *parent);
    void inorderTraversal(TreeNode *parent);
    void postorderTraversal(TreeNode *parent);
};

void BinaryTree::preorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    cout << " " << parent->val;
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void BinaryTree::inorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    inorderTraversal(parent->left);
    cout << " " << parent->val;
    inorderTraversal(parent->right);
}

void BinaryTree::postorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    cout << " " << parent->val;
}

class Solution {
private:
    ListNode *current;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //find size
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        current = head;

        //do inorder traversal
        return inorder(0, count-1);

    }

    TreeNode *inorder(int start, int end){
        if(start > end)
            return NULL;

        int mid = (start+end)/2;

        TreeNode *left = inorder(start, mid-1);
        TreeNode *newNode = new TreeNode(current->val);
        current = current->next;
        TreeNode *right = inorder(mid+1, end);

        newNode->left = left;
        newNode->right = right;

        return newNode;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const int test[] = {-10,-3,0,5,9};
    LinkedList ll(test, sizeof(test)/sizeof(test[0]));

    cout << "Display Linked List :";
    ll.display();

    Solution sol;
    TreeNode *answer = sol.sortedListToBST(ll.head);

    BinaryTree BT;
    cout << "preorder Traversal:";
    BT.preorderTraversal(answer);
    cout << endl;

    cout << "inorder Traversal:";
    BT.inorderTraversal(answer);
    cout << endl;

    return 0;
}
/*==============================================================*/