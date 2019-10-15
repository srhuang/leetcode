/*****************************************************************
Name    :flatten
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191015 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

/*==============================================================*/
//Data structure
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(-1), left(NULL), right(NULL){};
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *input);

    void preorderTraversal(TreeNode *parent);
    void inorderTraversal(TreeNode *parent);
    void postorderTraversal(TreeNode *parent);
};

BinaryTree::BinaryTree(const char *input)
{
    stringstream ss;
    ss << input;

    string temp;
    getline(ss, temp, ',');
    root = new TreeNode(stoi(temp));

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue<TreeNode*> q;
    TreeNode *current = root;
    string input;

    while(getline(ss, input, ',')){
        //left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(getline(ss, input, ',')))
            break;

        //right child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->right = newNode;
            q.push(newNode);
        }

        current = q.front();
        q.pop();
    }
}

void BinaryTree::preorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    //do the right things
    cout << " " << parent->val;
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void BinaryTree::inorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    inorderTraversal(parent->left);

    //do the right things
    cout << " " << parent->val;

    inorderTraversal(parent->right);
}

void BinaryTree::postorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);

    //do the right things
    cout << " " << parent->val;
}

/*==============================================================*/
//Solution
class Solution {
public:
    void flatten(TreeNode* root) {
        if(NULL==root)
            return;

        //divide and conquer
        flatten(root->left);
        flatten(root->right);

        //combine
        if(root->left != NULL){
            TreeNode *temp = root->right;

            //merge left child into right child
            root->right = root->left;
            root->left = NULL;

            //insert right child to the end of left child
            TreeNode *current = root;
            while(current->right){
                current = current->right;
            }
            current->right = temp;
        }
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,5,3,4,x,6";
    BinaryTree BT(input);

    cout << "preorder :";
    BT.preorderTraversal(BT.root);
    cout << endl;

    cout << "inorder :";
    BT.inorderTraversal(BT.root);
    cout << endl;

    Solution sol;
    sol.flatten(BT.root);

    cout << "after preorder :";
    BT.preorderTraversal(BT.root);
    cout << endl;

    cout << "after inorder :";
    BT.inorderTraversal(BT.root);
    cout << endl;

    return 0;
}
/*==============================================================*/