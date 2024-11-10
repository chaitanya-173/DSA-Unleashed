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

void inorder(Node* root, vector<int> &v) {
    //base case
    if(root == NULL)
        return;
    
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}

Node* inorderToBST(vector<int> v, int s, int e) {
    //base case
    if(s > e)
        return NULL;
    
    int mid = (s+e)/2;
    Node* root = new Node(v[mid]);
    root -> left = inorderToBST(v, s, mid-1);
    root -> right = inorderToBST(v, mid+1, e);
    return root;
}

//10 8 12 4 16 2 20 -1
int main() {

    Node* root = NULL;

    cout << "Enter BST elements: " << endl;
    takeInput(root);

    cout << endl << "Printing BST: " << endl;
    printByLevelOrder(root);

    vector<int> v;
    inorder(root, v);
    
    Node* newRoot = inorderToBST(v, 0, v.size()-1);
    cout << endl << "Balanced BST: " << endl;
    printByLevelOrder(newRoot);


}