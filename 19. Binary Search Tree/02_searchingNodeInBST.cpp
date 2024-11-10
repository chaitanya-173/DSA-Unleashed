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

//insertion in BST
Node* insertIntoBST(Node* root, int d) {
    //base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root -> data) {
        //right part mein insert krna hai
        root -> right = insertIntoBST(root -> right, d);
    }
    else {
        //left part mein insert krna hai
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
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

bool searchInBST(Node* root, int x) {  //recursively (SC - O(n))
    //base case
    if(root == NULL)
        return false;
    if(root -> data == x)
        return true;
    
    if(root -> data > x) {
        //left part mein search kro
        return searchInBST(root -> left, x);
    }
    else {
        //right part mein search kro
        return searchInBST(root -> right, x);
    }
}

bool searchInBSTBetter(Node* root, int x) {  //iteratively (SC - O(1))

    Node* temp = root;

    while(temp != NULL) {
        if(temp -> data == x) 
            return true;

        else if(temp -> data > x)
            temp = temp -> left;

        else
            temp = temp -> right;    
    }
    return false;
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    printByLevelOrderTraversal(root);

    cout << endl << searchInBST(root, 5) << endl;
    cout << searchInBSTBetter(root, 5) << endl;
    
}