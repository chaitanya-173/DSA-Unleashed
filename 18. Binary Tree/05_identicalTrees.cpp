#include <iostream>
#include <queue>
using namespace std;

class Node{
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

void buildTreeLevelWise(Node* &root) {
    queue<Node*> q;
    cout << "Enter root node: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp -> data << ": ";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }
        
        cout << "Enter data for right of " << temp -> data << ": ";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
        
    }
}

void printTreeLevelTraversal(Node* &root) {
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


bool isIdentical(Node* r1, Node* r2) {
    //base case
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right);
    bool value = r1->data == r2->data;

    if(left && right && value) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    Node* r1 = NULL;
    Node* r2 = NULL;
    buildTreeLevelWise(r1);
    buildTreeLevelWise(r2);
    printTreeLevelTraversal(r1);  
    printTreeLevelTraversal(r2);

    cout << "Identical or not: " << isIdentical(r1, r2);

}