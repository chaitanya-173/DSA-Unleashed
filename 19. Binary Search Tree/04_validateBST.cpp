#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    //constructor
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

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

void inorder(Node* root) {  //LNR
    //base case
    if(root == NULL) {
        return;
    }
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
        //left part mein insert krna hai
        insertIntoBST(root -> left, d);
    }
    else {
        //right part mein insert krna hai
        insertIntoBST(root -> right, d);
    }
}

void takeInput(Node* &root) {

    int data;
    cin >> data;

    while(data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

bool isValidBST(Node* root, int min, int max) {
    //base case
    if(root == NULL)
    return true;

    if(root -> data >= min && root -> data <= max) {
        bool left = isValidBST(root -> left, min, root -> data);
        bool right = isValidBST(root -> right, root -> data, max);
        return left && right;
    }
    else 
        return false;
}

//50 20 70 10 30 90 110 -1
int main() {

    Node* root = NULL;

    cout << endl << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << endl << "Printing the BST: " << endl;
    printByLevelOrderTraversal(root);
    
    cout << endl << "Inorder print: " << endl;
    inorder(root);

    cout << endl << "IsValid BST: " << isValidBST(root, INT_MIN, INT_MAX);

}