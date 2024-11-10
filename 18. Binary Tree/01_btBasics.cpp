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

Node* buildTree(Node* root) {    //first way to build a tree
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for insertion to left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for insertion to right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  //separator

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                //queue still have some child nodes
                q.push(NULL);  //separator
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
}  //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1

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

void buildFromLevelOrder(Node* &root) {   //second way to build a tree
    queue<Node*> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << ": ";
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << ": ";
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {

    Node* root = NULL;

    //creating a tree;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Printing inorder traversal: " << endl;
    inorder(root);
    cout << endl;

    cout << "Printing preorder traversal: " << endl;
    preorder(root);
    cout << endl;

    cout << "Printing postorder traversal: " << endl;
    postorder(root);
    cout << endl;
    

    //buildFromLevelOrder(root);
    //levelOrderTraversal(root);

}