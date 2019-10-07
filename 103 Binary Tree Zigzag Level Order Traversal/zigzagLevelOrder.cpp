/*****************************************************************
Name    :zigzagLevelOrder
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191006 Initial Version
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
    TreeNode() : val(-1), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
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
        //left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input))
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

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        bool zigzag = false;
        if(!root)
            return result;

        //queue init
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        zigzag = false;

        vector<int> curLevel;
        while(!q.empty()){
            //pop
            TreeNode *current = q.front();
            q.pop();

            if(NULL == current){//end of the level
                //check zigzag
                if(zigzag){
                    reverse(curLevel.begin(), curLevel.end());
                    zigzag=false;
                }else{
                    zigzag=true;
                }

                result.push_back(curLevel);
                curLevel.clear();

                //check queue if empty
                if(q.size()>0){
                    //end of the next level
                    q.push(NULL);
                }
            }else{
                curLevel.push_back(current->val);
                if(current->left)   q.push(current->left);
                if(current->right)  q.push(current->right);
            }
        }

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "3 9 20 x x 15 7";
    BinaryTree BT(input);

    Solution sol;
    vector< vector<int> > answer = sol.zigzagLevelOrder(BT.root);
    vector< vector<int> >::iterator it_second;
    vector<int>::iterator it_first;
    for(it_second=answer.begin(); it_second!=answer.end(); it_second++){
        for(it_first=(*it_second).begin(); it_first!=(*it_second).end(); it_first++){
            cout << (*it_first) << " " ;
        }
        cout << endl;
    }

    return 0;
}
/*==============================================================*/