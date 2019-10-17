/*****************************************************************
Name    :postorderTraversal
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191017 Initial Version
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* parent, vector<int> &result)
    {
        if(NULL == parent)
            return;

        if(parent->left)
            dfs(parent->left, result);
        if(parent->right)
            dfs(parent->right, result);

        //do the right things
        result.push_back(parent->val);
    }

    vector<int> postorderTraversalIteration(TreeNode* root) {
        vector<int> result;
        if(NULL == root)
            return result;

        stack<TreeNode*> st;
        TreeNode *current = root;
        do{
            //move to the leftmost and push right,parent into stack
            while(current){
                if(current->right)
                    st.push(current->right);

                st.push(current);
                current = current->left;
            }

            //pop the stack and handle
            current = st.top();
            st.pop();

            //right chiild handle first
            if(current->right && !st.empty() && (st.top()==current->right) )
            {
                st.pop();
                st.push(current);
                current = current->right;
            }else{//left and right child has been handled
                result.push_back(current->val);
                current = NULL; //only need to pop the stack
            }

        }while(!st.empty());

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,3,x,x,4,5,6,7";
    BinaryTree BT(input);

    Solution sol;
    vector<int> recursion = sol.postorderTraversal(BT.root);

    vector<int>::iterator it;
    cout << "Recursion :";
    for(it=recursion.begin(); it!=recursion.end(); it++)
    {
        cout << " " << *it ;
    }
    cout << endl;

    vector<int> iteration = sol.postorderTraversalIteration(BT.root);
    cout << "Iteration :";
    for(it=iteration.begin(); it!=iteration.end(); it++)
    {
        cout << " " << *it ;
    }
    cout << endl;

    return 0;
}
/*==============================================================*/