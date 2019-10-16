/*****************************************************************
Name    :maxPathSum
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191016 Initial Version
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

/*==============================================================*/
//Solution
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    //return the max value when path through the parent
    int dfs(TreeNode *parent, int &maxSum)
    {
        if(NULL==parent)
            return 0;

        //zero means do not choose
        int left = max(0, dfs(parent->left, maxSum));
        int right = max(0, dfs(parent->right, maxSum));

        //compare the path through the parent
        maxSum = max(left+right+parent->val, maxSum);

        //return the path through either left child or right chiild
        return (parent->val + max(left, right));
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "-10,9,20,x,x,15,7";
    BinaryTree BT(input);

    Solution sol;
    int answer = sol.maxPathSum(BT.root);
    cout << "answer is : " << answer << endl;
    return 0;
}
/*==============================================================*/