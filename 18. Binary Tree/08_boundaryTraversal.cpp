#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout << "Enter root data: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node data for " << temp -> data << ": ";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node data for " << temp -> data << ": ";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

void printByLevelOrderTraversal(Node* &root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
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

void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root -> left == NULL && root -> right == NULL) )
        return;
    
    ans.push_back(root -> data);

    if(root -> left)    
        traverseLeft(root -> left, ans);
    else 
        traverseLeft(root -> right, ans);
}

void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL) 
        return;
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }

    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root -> left == NULL && root -> right == NULL) ) 
        return;

    if(root -> right)
        traverseRight(root -> right, ans);
    else 
        traverseRight(root -> left, ans);
    
    //wapas aagye
    ans.push_back(root -> data);
}

vector<int> boundary(Node* root, vector<int> &ans) {
    
    if(root == NULL) 
        return ans;
    
    ans.push_back(root -> data);

    //traverse left part
    traverseLeft(root -> left, ans);

    //taraverse leaf nodes
    

    //left subtree
    traverseLeaf(root -> left, ans);
    //right subtree
    traverseLeaf(root -> right, ans);

    //traverse right part
    traverseRight(root -> right, ans);

    return ans;
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    vector<int> ans;
    boundary(root, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

}