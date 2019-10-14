/*****************************************************************
Name    :minDepth
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191014 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <string>
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
    void preorderTraversalRecursion(TreeNode *parent);
    void inorderTraversalRecursion(TreeNode *parent);
};

BinaryTree::BinaryTree(const char *input)
{
    stringstream ss;
    string temp;
    ss << input;

    //root
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

void BinaryTree::preorderTraversalRecursion(TreeNode *parent)
{
    if(NULL == parent){
        return;
    }

    //do the right things
    cout << " " << parent->val;
    preorderTraversalRecursion(parent->left);
    preorderTraversalRecursion(parent->right);
}

void BinaryTree::inorderTraversalRecursion(TreeNode *parent)
{
    if(NULL == parent){
        return;
    }

    inorderTraversalRecursion(parent->left);
    //do the right things
    cout << " " << parent->val;
    inorderTraversalRecursion(parent->right);
}

/*==============================================================*/
//Solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(NULL == root)
            return 0;

        if(NULL==root->left || NULL==root->right)
            return max(minDepth(root->left), minDepth(root->right))+1;

        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "3,9,20,x,x,15,7";
    BinaryTree BT(input);

    BT.preorderTraversalRecursion(BT.root);
    cout << endl;
    BT.inorderTraversalRecursion(BT.root);
    cout << endl;

    Solution sol;
    int answer = sol.minDepth(BT.root);
    cout << "answer is : " << answer << endl;

    return 0;
}
/*==============================================================*/