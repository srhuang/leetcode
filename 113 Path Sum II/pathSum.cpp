/*****************************************************************
Name    :pathSum
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

        if(!(getline(ss, input, ','))){
            break;
        }

        //right child
        if(input.compare("x")){
            TreeNode * newNode = new TreeNode(stoi(input));
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> path;

        backtracking(root, sum, path, result);

        return result;
    }

    void backtracking(
      TreeNode *parent, int sum, vector<int> &path, vector<vector<int> > &result){
        if(NULL==parent)
            return;

        //tracking
        path.push_back(parent->val);

        //checking
        if((NULL==parent->left) && (NULL==parent->right) && sum==parent->val)
            result.push_back(path);

        //DFS
        backtracking(parent->left, sum-parent->val, path, result);
        backtracking(parent->right, sum-parent->val, path, result);

        //backtracking
        path.pop_back();
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "5,4,8,11,x,13,4,7,2,x,x,5,1";
    BinaryTree BT(input);

    Solution sol;
    vector<vector<int> > answer = sol.pathSum(BT.root, 22);
    vector<vector<int> >::iterator it_second;
    vector<int>::iterator it_first;
    for(it_second=answer.begin(); it_second!=answer.end(); it_second++)
    {
        for(it_first=(*it_second).begin(); it_first!=(*it_second).end(); it_first++)
        {
            cout << " " << *it_first;
        }
        cout << endl;
    }

    return 0;
}
/*==============================================================*/