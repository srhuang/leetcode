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
private:
    int preIndex;
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int size = inorder.size();
        preIndex=0;
        return buildTreePre(preorder, inorder, 0, size-1);
    }

    TreeNode *buildTreePre(
        vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd)
    {
        //check invalid inorder index
        if(inStart > inEnd){
            return NULL;
        }

        TreeNode *newNode = new TreeNode(preorder[preIndex++]);

        if(inStart == inEnd)
            return newNode;

        //find the position in inorder
        int inIndex = search(inorder, inStart, inEnd, newNode->val);

        newNode->left = buildTreePre(preorder, inorder, inStart, inIndex-1);
        newNode->right = buildTreePre(preorder, inorder, inIndex+1, inEnd);

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
    int input[]={-1};
    vector<int> preorder(input, input+(sizeof(input)/sizeof(input[0])) );

    int input2[]={-1};
    vector<int> inorder(input2, input2+(sizeof(input2)/sizeof(input2[0])) );

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << root->val << endl;

    return 0;
}
/*==============================================================*/