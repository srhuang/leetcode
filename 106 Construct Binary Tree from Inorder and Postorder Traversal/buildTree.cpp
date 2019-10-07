/*****************************************************************
Name    :buildTree
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        int inSize = inorder.size();
        return buildTreePost(inorder, postorder, 0, inSize-1, &postIndex);
    }

    TreeNode *buildTreePost(
        vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int *postIndex)
    {
        //check invalid index
        if(inStart > inEnd)
            return NULL;

        TreeNode *newNode = new TreeNode(postorder[*postIndex]);
        (*postIndex)--;

        if(inStart == inEnd)
            return newNode;

        //find the position in the inorder
        int inIndex = search(inorder, inStart, inEnd, newNode->val);

        newNode->right=buildTreePost(inorder, postorder, inIndex+1, inEnd, postIndex);
        newNode->left=buildTreePost(inorder, postorder, inStart, inIndex-1, postIndex);

        return newNode;

    }

    int search(vector<int>& input, int start, int end, int target)
    {
        for(int i=start; i<=end; i++){
            if(input.at(i) == target)
                return i;
        }
        return -1;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    int inorder_ptr[] = {9,3,15,20,7};
    int postorder_ptr[] = {9,15,7,20,3};

    vector<int> inorder(inorder_ptr, 
        inorder_ptr+(sizeof(inorder_ptr)/sizeof(inorder_ptr[0])) );
    vector<int> postorder(postorder_ptr, 
        postorder_ptr+(sizeof(postorder_ptr)/sizeof(postorder_ptr[0])) );

    Solution sol;
    TreeNode *root = sol.buildTree(inorder, postorder);

    cout<<root->val<<endl;
    
    return 0;
}
/*==============================================================*/