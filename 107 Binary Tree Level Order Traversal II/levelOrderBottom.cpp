/*****************************************************************
Name    :levelOrderBottom
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191007 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
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

/*==============================================================*/
//Function area
class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *str);

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
    string input;

    while(ss >> input){
        //cout << "input=" << input << endl;

        //handle the left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input)){
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

class Solution {
public:
    vector<vector<int> > answer;
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        //from bottom
        reverse(answer.begin(), answer.end());
        return answer;
    }

    void levelOrder(TreeNode *parent, int level)
    {
        if(!parent)
            return;

        while(answer.size() <= level){
            answer.push_back(vector<int>());
        }

        answer[level].push_back(parent->val);

        levelOrder(parent->left, level+1);
        levelOrder(parent->right, level+1);
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "3 9 20 x x 15 7";
    BinaryTree BT(input);

    Solution sol;
    vector< vector<int> >answer = sol.levelOrderBottom(BT.root);
    vector< vector<int> >::iterator it_second;
    vector<int>::iterator it_first;
    for(it_second=answer.begin(); it_second!=answer.end(); it_second++){
        for(it_first=(*it_second).begin(); it_first!=(*it_second).end(); it_first++){
            cout << *it_first << " ";
        }
        cout<<endl;
    }

    return 0;
}
/*==============================================================*/