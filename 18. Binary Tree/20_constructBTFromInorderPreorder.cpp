#include <iostream>
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

int findPosition(int in[], int element, int n) {
    for(int i=0; i<n; i++) {
        if(in[i] == element)
            return i;
    }
    return -1;
}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
    //base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int inorderPosition = findPosition(in, element, n);

    //recursive calls
    root -> left = solve(in, pre, index, inorderStart, inorderPosition-1, n);
    root -> right = solve(in, pre, index, inorderPosition+1, inorderEnd, n);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    int preorderIndex = 0;
    Node* ans = solve(in, pre, preorderIndex, 0, n-1, n);
    return ans;
}

Node* postorderPrint(Node* root) {
    //base case
    if(root == NULL)
        return NULL;
    
    postorderPrint(root -> left);
    postorderPrint(root -> right);

    cout << root -> data << " ";
}

int main() {

    int in[6] = {3,1,4,0,5,2};
    int pre[6] = {0,1,3,4,2,5};

    Node* root = buildTree(in, pre, 6);
    postorderPrint(root);
    
}