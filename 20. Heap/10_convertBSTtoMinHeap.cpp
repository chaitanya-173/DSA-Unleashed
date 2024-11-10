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

void printFromLevelOrder(Node* root) {
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
            if(temp -> left) 
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

void inorder(Node* root, vector<int> &inorderArr) {
    if(root == NULL)
        return;
    
    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

void preorderFill(Node* root, vector<int> &inorderArr, int &index) {
    if(root == NULL) 
        return;
    
    // Copy the next element from the inorder array
    root->data = inorderArr[index++];

    // Fill left and right subtree
    preorderFill(root->left, inorderArr, index);  
    preorderFill(root->right, inorderArr, index);
}

// Function to convert BST to Min Heap
void convertBSTtoMinHeap(Node* root) {

    vector<int> inorderArr;
    // Step 1: Perform inorder traversal to store values in sorted order
    inorder(root, inorderArr);

    int index = 0;

    // Step 2: Perform preorder traversal and fill nodes with inorder values
    preorderFill(root, inorderArr, index);

}

void preorderPrint(Node* root) {
    if(root == NULL) 
        return;

    cout << root -> data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}

int main() {

    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << endl << "Initial BST: " << endl;
    printFromLevelOrder(root);
    
    cout << endl << "Initial preorder print(BST): ";
    preorderPrint(root);

    convertBSTtoMinHeap(root);

    cout << endl << "Final preorder print(Min Heap): ";
    preorderPrint(root);

    cout << endl << "Converted BST to minHeap: " << endl;
    printFromLevelOrder(root);

}