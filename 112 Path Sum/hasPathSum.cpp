/*****************************************************************
Name    :hasPathSum
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

};

BinaryTree::BinaryTree(const char *input)
{
    stringstream ss;
    string temp;
    ss << input;

    getline(ss, temp, ',');
    root = new TreeNode(stoi(temp));

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue <TreeNode*> q;
    TreeNode *current = root;
    string input;

    while(getline(ss, input, ',')){
        //handle left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(getline(ss, input, ','))){
            break;
        }

        //handle right child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root)
            return false;

        int last_sum = sum - root->val;
        if(NULL==root->left && NULL==root->right){
            return (last_sum==0);
        }

        return (hasPathSum(root->left, last_sum) || hasPathSum(root->right, last_sum));
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,3,4,5,6,7,8";
    BinaryTree BT(input);

    Solution sol;
    bool answer = sol.hasPathSum(BT.root, 8);
    cout << "answer is : " << answer <<endl;

    return 0;
}
/*==============================================================*/