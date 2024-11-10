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

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex) {
    //base case
    if(index >= n || inorderStart > inorderEnd) 
        return NULL;

    //create a root node for element
    int element = pre[index++];
    Node* root = new Node(element);

    //find element's index in inorder array
    int inorderPosition = nodeToIndex[element];

    //recursive calls
    root -> left = solve(in, pre, index, inorderStart, inorderPosition-1, n, nodeToIndex);
    root -> right = solve(in, pre, index, inorderPosition+1, inorderEnd, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    int preorderIndex = 0;

    //create nodes to index mapping
    map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, n);

    Node* ans = solve(in, pre, preorderIndex, 0, n-1, n, nodeToIndex);
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