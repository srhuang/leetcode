/*****************************************************************
Name    :sortedArrayToBST
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191007 Initial Version
*****************************************************************/
#include <iostream>
#include <vector>
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
public:
    vector<int> result;
    void preorderTraversal(TreeNode *parent);
    void inorderTraversal(TreeNode *parent);
    void postorderTraversal(TreeNode *parent);
};

void BinaryTree::preorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    result.push_back(parent->val);
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void BinaryTree::inorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    inorderTraversal(parent->left);
    result.push_back(parent->val);
    inorderTraversal(parent->right);
}

void BinaryTree::postorderTraversal(TreeNode *parent)
{
    if(NULL == parent)
        return;

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    result.push_back(parent->val);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        //terminal condition
        if(start>end)
            return NULL;

        int midIndex = (start+end) / 2;
        TreeNode *newNode = new TreeNode(nums[midIndex]);
        newNode->left = sortedArrayToBST(nums, start, midIndex-1);
        newNode->right = sortedArrayToBST(nums, midIndex+1, end);
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums){
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    int test[] = {-10,-3,0,5,9};
    vector<int> nums(test, test+(sizeof(test)/sizeof(test[0])));

    Solution sol;
    TreeNode *answer = sol.sortedArrayToBST(nums);

    BinaryTree BT;
    vector<int>::iterator it;

    //preorder
    BT.result.clear();
    BT.preorderTraversal(answer);
    cout << "Preorder :";
    for(it=BT.result.begin(); it!=BT.result.end(); it++){
        cout << " " << *it;
    }
    cout << endl;

    //inorder
    BT.result.clear();
    BT.inorderTraversal(answer);
    cout << "Inorder :";
    for(it=BT.result.begin(); it!=BT.result.end(); it++){
        cout << " " << *it;
    }
    cout << endl;

    //postorder
    BT.result.clear();
    BT.postorderTraversal(answer);
    cout << "Postorder :";
    for(it=BT.result.begin(); it!=BT.result.end(); it++){
        cout << " " << *it;
    }
    cout << endl;

    return 0;
}
/*==============================================================*/