/*****************************************************************
Name    :connect
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191016 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

/*==============================================================*/
//Data structure
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    Node *root;
    BinaryTree(const char *input);
};

BinaryTree::BinaryTree(const char *input)
{
    stringstream ss;
    ss << input;

    string temp;
    getline(ss, temp, ',');
    root = new Node(stoi(temp), NULL, NULL, NULL);

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue<Node*> q;
    Node *current = root;
    string input;

    while(getline(ss, input, ',')){
        //left child
        if(input.compare("x")){
            Node *newNode = new Node(stoi(input), NULL, NULL, NULL);
            current->left = newNode;
            q.push(newNode);
        }

        if(!(getline(ss, input, ',')))
            break;

        //right child
        if(input.compare("x")){
            Node *newNode = new Node(stoi(input), NULL, NULL, NULL);
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
    Node* connect(Node* root) {
        if(NULL==root)
            return NULL;

        queue<Node*> q;
        Node *pre = NULL;
        Node *current = NULL;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            pre = current;
            current = q.front();
            q.pop();

            //check level end
            if(NULL == current){
                pre->next = NULL;
                if(q.size()>0)
                    q.push(NULL);
            }else{
                if(NULL != pre)
                    pre->next = current;
                if(current->left)   q.push(current->left);
                if(current->right)  q.push(current->right);
            }
        }//while

        return root;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    const char *input = "1,2,3,4,5,6,7";
    BinaryTree BT(input);

    Solution sol;
    sol.connect(BT.root);

    return 0;
}
/*==============================================================*/