#include <iostream>
#include <map>
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

void createMapping(int in[], map<int,int> &nodeToIndex, int n) {
    for(int i=0; i<n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex) {
    //base case
    if(index < 0 || inorderStart > inorderEnd) 
        return NULL;

    //create a root node for element
    int element = post[index--];
    Node* root = new Node(element);

    //find element's index in inorder array
    int inorderPosition = nodeToIndex[element];

    //recursive calls (in case of postorder and inorder, first we build right tree)
    root -> right = solve(in, post, index, inorderPosition+1, inorderEnd, n, nodeToIndex);  //change (right before left)
    root -> left = solve(in, post, index, inorderStart, inorderPosition-1, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n) {
    int postorderIndex = n-1;

    //create nodes to index mapping
    map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, n);

    Node* ans = solve(in, post, postorderIndex, 0, n-1, n, nodeToIndex);
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

    int in[8] = {4,8,2,5,1,6,3,7};
    int post[8] = {8,4,5,2,6,7,3,1};

    Node* root = buildTree(in, post, 8);
    postorderPrint(root);
    
}