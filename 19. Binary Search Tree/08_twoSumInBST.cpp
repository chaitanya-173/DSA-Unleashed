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

void printByLevelOrder(Node* root) {
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

void inorder(Node* root, vector<int> &v) {  //LNR
    //base case
    if(root == NULL)
        return;
    
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}

void insertIntoBST(Node* &root, int d) {
    //base case
    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root -> data) {
        insertIntoBST(root -> left, d);
    }
    else {
        insertIntoBST(root -> right, d);
    }
}

void takeInput(Node* &root) {
    int d;
    cin >> d;
    while(d != -1) {
        insertIntoBST(root, d);
        cin >> d;
    }
}

bool twoSumInBST(Node* root, int target) {
    vector<int> v;
    //store inorder => sorted order
    inorder(root, v);

    //2 pointer approach
    int i=0, j=v.size()-1;
    while(i<j) {
        int sum = v[i] + v[j];

        if(sum == target)
            return true;
        else if(sum > target)
            j--;
        else
            i++;
    }
    return false;
}

//10 6 12 2 8 11 15 -1
int main() {

    Node* root = NULL;

    cout << "Enter BST elements: " << endl;
    takeInput(root);

    cout << endl << "Printing BST: " << endl;
    printByLevelOrder(root);

    cout << endl << "Two sum or not: " << twoSumInBST(root, 20) << endl;

}