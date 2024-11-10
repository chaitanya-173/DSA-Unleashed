#include <iostream>
#include <queue>
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

void preorder(Node* root) {  //NLR
    //base case
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";  
    preorder(root -> left);  
    preorder(root -> right);  
}

void postorder(Node* root) {  //LRN
    //base case
    if(root == NULL) {
        return;
    }
    postorder(root -> left);  
    postorder(root -> right);  
    cout << root -> data << " ";  
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

int minVal(Node* root) {
    Node* temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp -> data;
}

int maxVal(Node* root) {
    Node* temp = root;
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp -> data;
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    printByLevelOrderTraversal(root);

    cout << "Printing inorder: " << endl;
    inorder(root);

    cout << endl << "Printing preorder: " << endl;
    preorder(root);

    cout << endl << "Printing postorder: " << endl;
    postorder(root);

    cout << endl << "Minimum value of BST: " << minVal(root) << endl;
    cout << "Maximum value of BST: " << maxVal(root) << endl;
    ;

}