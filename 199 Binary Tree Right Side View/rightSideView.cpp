/*****************************************************************
Name    :rightSideView
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191018 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <stack>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(NULL == root)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        TreeNode *pre = NULL;
        TreeNode *current = NULL;

        while(!q.empty()){
            pre = current;
            current = q.front();
            q.pop();

            //check level end
            if(NULL == current){
                result.push_back(pre->val);
                if(!q.empty())
                    q.push(NULL);
            }else{
                if(current->left)   q.push(current->left);
                if(current->right)  q.push(current->right);
            }
        }//while

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,3,x,5,x,4";
    BinaryTree BT(input);

    Solution sol;
    vector<int> result = sol.rightSideView(BT.root);
    vector<int>::iterator it;
    cout << "Solution is";
    for(it=result.begin(); it!=result.end(); it++)
    {
        cout << " " << *it;
    }
    cout <<endl;

    return 0;
}
/*==============================================================*/