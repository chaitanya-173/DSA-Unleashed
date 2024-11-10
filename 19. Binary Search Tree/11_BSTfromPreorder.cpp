#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

void preorder(Node* root, vector<int> &v) {  //NLR
    //base case
    if(root == NULL)
        return;
    
    v.push_back(root -> data);
    preorder(root -> left, v);
    preorder(root -> right, v);
}

Node* BSTfromPreorder(vector<int> &preorderV, int mini, int maxi, int &i) {
    //base case
    if(i >= preorderV.size())
       return NULL;
    if(preorderV[i] < mini || preorderV[i] > maxi) 
        return NULL;
    
    Node* newRoot = new Node(preorderV[i++]);
    newRoot -> left = BSTfromPreorder(preorderV, mini, newRoot -> data, i);
    newRoot -> right = BSTfromPreorder(preorderV, newRoot -> data, maxi, i);
    return newRoot;
    
}  //mini ki zrurt nhi hai, uske bina bhi krke dkh lena

//10 4 3 7 40 55 -1
int main() {

    Node* root = NULL;

    cout << "Enter BST elements: " << endl;
    takeInput(root);

    cout << endl << "Printing BST: " << endl;
    printByLevelOrder(root);

    vector<int> v;
    preorder(root, v);
    cout << endl << "Preorder: " << endl;
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }

    int i=0; 
    Node* newRoot = BSTfromPreorder(v, INT_MIN, INT_MAX, i);
    cout << endl << endl << "New BST: " << endl;
    printByLevelOrder(newRoot);


}