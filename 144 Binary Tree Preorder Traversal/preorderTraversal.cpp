/*****************************************************************
Name    :preorderTraversal
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
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *str);
};

BinaryTree::BinaryTree(const char *str)
{
    stringstream ss;
    string temp;
    ss << str;

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
        //handle the left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(getline(ss, input, ','))){
            break;
        }
        
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode *parent, vector<int> &result)
    {
        if(NULL==parent)
            return;

        //do the right things
        result.push_back(parent->val);

        dfs(parent->left, result);
        dfs(parent->right, result);
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,3,x,x,4,5,6,7";
    BinaryTree BT(input);

    return 0;
}
/*==============================================================*/