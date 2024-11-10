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

void inorder(Node* root, vector<Node*> &v) {  //LNR
    //base case
    if(root == NULL)
        return;
    
    inorder(root -> left, v);
    v.push_back(root);
    inorder(root -> right, v);
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

Node* flattenBSTtoSortedLL(Node* root) {
    vector<Node*> v;
    inorder(root, v);
    
    for(int i=0; i<v.size()-1; i++) {
        v[i] -> right = v[i+1];
        v[i] -> left = NULL;
    }
    v[v.size()-1] -> right = NULL;
    return v[0];
}

//5 2 7 1 3 6 8 9 -1
int main() {

    Node* root = NULL;

    cout << "Enter BST elements: " << endl;
    takeInput(root);

    cout << endl << "Printing BST: " << endl;
    printByLevelOrder(root);

    cout << endl << "Printing Flattened sorted LL: " << endl;
    Node* newRoot = flattenBSTtoSortedLL(root);
    Node* temp = newRoot;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> right;
    }

}