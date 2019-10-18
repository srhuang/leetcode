/*****************************************************************
Name    :BSTIterator
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
    TreeNode():val(-1), left(NULL), right(NULL){};
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *input);
    void preorderTraversal(TreeNode *parent);
    void inorderTraversal(TreeNode *parent);
    void postorderTraversal(TreeNode *parent);
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

void BinaryTree::preorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    stack<TreeNode*> st;
    st.push(parent);

    while(!st.empty()){
        TreeNode *current = st.top();
        st.pop();

        //do the right thing
        cout << " " << current->val;

        if(current->right)
            st.push(current->right);
        if(current->left)
            st.push(current->left);
    }
}

void BinaryTree::inorderTraversal(TreeNode *parent)
{
    stack<TreeNode*> st;
    TreeNode *current = parent;

    while(current || !st.empty()){
        //step 1:reach the leftmost node
        while(current){
            st.push(current);
            current = current->left;
        }

        //step 2:pop the stack
        current = st.top();
        st.pop();

        //step 3:do the right thing
        cout << " " << current->val;

        //step 4:handle the right child if need
        current = current->right;
    }
}

void BinaryTree::postorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    stack<TreeNode*> st;
    TreeNode *current = parent;

    do{
        //step 1:reach the leftmost node
        while(current){
            //push right child
            if(current->right)
                st.push(current->right);
            //push the current
            st.push(current);

            current = current->left;
        }

        //step 2:pop the stack
        current = st.top();
        st.pop();

        //step 3:handle the right child first
        if(current->right && !st.empty() && st.top() == current->right)
        {
            st.pop();
            st.push(current);
            current = current->right;
        }else{//step 4:do the right thing
            cout << " " << current->val;

            //for next pop
            current = NULL;
        }

    }while(!st.empty());
}

/*==============================================================*/
//Solution

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        //reach the leftmost node
        TreeNode *current = root;
        while(current){
            st.push(current);
            current = current->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *current = st.top();
        st.pop();

        //handle if right child
        if(current->right){
            TreeNode *temp = current->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }

        return current->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "7,3,15,x,x,9,20";
    BinaryTree BT(input);

    cout << "Preorder :";
    BT.preorderTraversal(BT.root);
    cout << endl;

    cout << "Inorder :";
    BT.inorderTraversal(BT.root);
    cout << endl;

    cout << "Postorder :";
    BT.postorderTraversal(BT.root);
    cout << endl;

    cout << "Solution :";
    BSTIterator BI(BT.root);
    while(BI.hasNext())
        cout << " " << BI.next();
    cout <<endl;

    return 0;
}
/*==============================================================*/