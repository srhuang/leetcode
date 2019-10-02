/*****************************************************************
Name    :isSymmetric
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190927 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

/*==============================================================*/
//Global area

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*==============================================================*/
//Class area
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
    ss << str;

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
        //cout << "input=" << input << endl;

        //handle the left child
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input)){
            break;
        }
        
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->right = newNode;
            q.push(newNode);
        }

        current = q.front();
        q.pop();
    }
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL)
            return false;

        return (node1->val==node2->val) && 
            isMirror(node1->right, node2->left) &&
            isMirror(node1->left, node2->right);
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *tree1 = "1 2 2 3 4 4 3";
    BinaryTree BT1(tree1);

    Solution sol;
    bool answer = sol.isSymmetric(BT1.root);

    cout << "Answer : " << answer << endl;
    return 0;
}
/*==============================================================*/