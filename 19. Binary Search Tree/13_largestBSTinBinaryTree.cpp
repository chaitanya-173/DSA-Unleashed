#include <iostream>
#include <queue>
#include <climits>
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

void buildFromLevelOrder(Node* &root) {   //second way to build a tree
    queue<Node*> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << ": ";
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << ": ";
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

void printByLevelOrder(Node* root) {
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
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root, int &ans) {
    //base case
    if(root == NULL) 
        return {INT_MIN, INT_MAX, true, 0};
    
    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root -> data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini) ) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(Node* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

//5 2 4 1 3 -1 -1 -1 -1 -1 -1

int main() {

    Node* root = NULL;

    buildFromLevelOrder(root); 

    cout << endl << "Printing Binary Tree: " << endl;
    printByLevelOrder(root);

    cout << endl << "Largest BST in Binary Tree: " << largestBST(root) << endl;

}