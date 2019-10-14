/*****************************************************************
Name    :isBalanced
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191014 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

/*==============================================================*/
//Data structure
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *input);

};

BinaryTree::BinaryTree(const char *input)
{
    stringstream ss;
    ss << input;

    root = new TreeNode;
    ss >> root->val;

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue<TreeNode*> q;
    TreeNode *current = root;
    char input;

    while(ss >> input){
        //handle the left child
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input))
            break;

        //handle the right child
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->right = newNode;
            q.push(newNode);
        }

        current = q.front();
        q.pop();
    }
}

/*==============================================================*/
//Solution

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return (depth(root)!=-1);
    }

    int depth(TreeNode *parent){
        if(NULL == parent)
            return 0;

        int left_depth = depth(parent->left);
        if(-1 == left_depth)
            return -1;

        int right_depth = depth(parent->right);
        if(-1 == right_depth)
            return -1;

        //check balance
        if(abs(left_depth-right_depth) > 1)
            return -1;

        return max(left_depth, right_depth)+1;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1 2 2 3 3 x x 4 4";
    BinaryTree BT(input);
    
    Solution sol;
    bool answer = sol.isBalanced(BT.root);

    cout << "answer is " << answer << endl;;

    return 0;
}
/*==============================================================*/