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

pair<int,int> predecessorSuccessor(Node* root, int key) {

    //find key
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp -> data != key) {
        if(key < temp -> data) {
            succ = temp -> data;
            temp = temp -> left;
        }
        else {
            pred = temp -> data;
            temp = temp -> right;
        }
    }

    // pred and succ

    //pred => left tree ka max value
    Node* leftTree = temp -> left;
    while(leftTree != NULL) {
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }

    //succ => right tree ka min value
    Node* rightTree = temp -> right;
    while(rightTree != NULL) {
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }

    return {pred, succ};

}

//5 4 8 2 6 10 3 7 -1
int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << endl << "Printing the BST: " << endl;
    printByLevelOrderTraversal(root);
    
    cout << endl << "Inorder print: " << endl;
    inorder(root);
    cout << endl;

    cout << endl << "Predecessor of 6: " << predecessorSuccessor(root, 6).first << endl;
    cout << "Successor of 6: " << predecessorSuccessor(root, 6).second << endl;

}
