#include <iostream>
#include <queue>
using namespace std;


class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void printByLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void insertIntoBST(TreeNode* &root, int d) {
    if(root == NULL) {
        root = new TreeNode(d);
        return;
    }

    if(d < root -> data) {
        insertIntoBST(root -> left, d);
    }
    else {
        insertIntoBST(root -> right, d);
    }
}