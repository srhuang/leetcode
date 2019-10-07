/*****************************************************************
Name    :maxDepth
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191007 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

/*==============================================================*/
//Global area
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
    BinaryTree(const char *str);
};

BinaryTree::BinaryTree(const char *input)
{
    //using string stream
    stringstream ss;
    ss << input;

    //new the root
    root = new TreeNode;
    ss >> root->val;

    //using level order construction
    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    //init
    queue<TreeNode*> q;
    TreeNode *current = root;
    string input;

    while(ss >> input){
        //left child
        if(input.compare("x")){ //!="x"
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        //check if there is another input
        if(!(ss >> input))
            break;

        //right child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->right = newNode;
            q.push(newNode);
        }

        //update current from queue
        current = q.front();
        q.pop();
    }
}

/*==============================================================*/
//Function area
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root==NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "3 9 20 x x 15 7";
    BinaryTree BT(input);
    
    Solution sol;
    int answer = sol.maxDepth(BT.root);
    cout << "answer : " << answer <<endl;

    return 0;
}
/*==============================================================*/