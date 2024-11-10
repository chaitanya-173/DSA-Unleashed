#include <iostream>
#include <queue>
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
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }      
    }   
}

void inorder(Node* root) {
    //base case
    if(root == NULL)
        return;
    
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void insertIntoBST(Node* &root, int d) {
    //base case
    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root -> data) {
        insertIntoBST(root -> left, d);
    }
    else {
        insertIntoBST(root -> right, d);
    }
}

void takeInput(Node* &root) {
    int d;
    cin >> d;
    while(d != -1) {
        insertIntoBST(root, d);
        cin >> d;
    }
}

int main() {

    Node* root = NULL;

    cout << endl << "Enter BST elements: " << endl; 
    takeInput(root);

    cout << endl << "Printing BST: " << endl;
    printByLevelOrder(root);

    cout << endl << "Inorder print: " << endl;
    inorder(root);

}