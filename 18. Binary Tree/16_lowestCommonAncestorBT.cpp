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

Node* lca(Node* root, int n1, int n2) {
    //base case
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node* leftAns = lca(root -> left, n1, n2);
    Node* rightAns = lca(root -> right, n1, n2);

    if(leftAns != NULL && rightAns != NULL) 
        return root;
    else if(leftAns != NULL && rightAns == NULL) 
        return leftAns;
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    else 
        return NULL;  
}

//5 2 3 6 -1 4 5 -1 8 -1 -1 21 -1 -1 -1 -1 -1
int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    Node* ans = lca(root, 21, 4);
    cout << ans -> data << endl;
    //ans should be 3

}