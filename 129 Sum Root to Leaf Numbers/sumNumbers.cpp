/*****************************************************************
Name    :sumNumbers
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

        if(!getline(ss, input, ','))
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode *parent, int sum)
    {
        if(NULL == parent)
            return 0;

        sum = sum*10 + parent->val;

        //return sum when meet leaf
        if(NULL==parent->left && NULL==parent->right){
            return sum;
        }

        int result = dfs(parent->left, sum);
        result += dfs(parent->right, sum);

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "4,9,0,5,1";
    BinaryTree BT(input);

    Solution sol;
    int answer = sol.sumNumbers(BT.root);
    cout << "answer is : " << answer << endl;
    return 0;
}
/*==============================================================*/