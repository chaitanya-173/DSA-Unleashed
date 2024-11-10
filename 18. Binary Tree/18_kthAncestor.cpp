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

Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL) 
        return NULL;
    if(root -> data == node)
        return root;
    
    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root -> right, k, node);

    //wapas aagye
    if(leftAns != NULL && rightAns == NULL) {
        k--;  
        if(k<=0) {
            k = INT_MAX;  //answer lock
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL) {
        k--;  
        if(k<=0) {
            k = INT_MAX;  //answer lock
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node* root, int k, int node) {
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)  //edge case dusra wala ki kahin kth element available he na ho
        return -1;
    else 
        return ans -> data;
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    cout << kthAncestor(root, 2, 4) << endl;

}