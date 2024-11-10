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

Node* deleteFromBST(Node* root, int val) {
    //base case
    if(root == NULL) 
        return root;
    
      
    if(root -> data == val) {
        //0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        //1 child
            //left child
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
            //right child
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        //2 child
        if(root -> left != NULL  && root -> right != NULL) {
            int mini = minVal(root -> right);
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }

    }
    else if(val < root -> data) {
        root -> left = deleteFromBST(root -> left, val);
    }
    else {
        root -> right = deleteFromBST(root -> right, val);
    }

}

//50 20 70 10 30 90 110 -1
int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    printByLevelOrderTraversal(root);
    
    cout << "Inorder print: " << endl;
    inorder(root);
    cout << endl;

    //DELETION
    root = deleteFromBST(root, 50);
    cout << "BST after deletion: " << endl;
    printByLevelOrderTraversal(root);
    cout << "Inorder print: " << endl;
    inorder(root);


}