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

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout << "Enter root data: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node data for " << temp -> data << ": ";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node data for " << temp -> data << ": ";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

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

void flatten(Node* &root) {
    Node* curr = root;
        
    while(curr != NULL) {
            
        if(curr -> left) {
            Node* pred = curr -> left;
            while(pred -> right) 
                pred = pred -> right;
                    
            pred -> right  = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;  //left part NULL
        }
            
        curr = curr -> right;
    }
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    flatten(root);

    cout << "flatten binary tree to linked list: " << endl;
    printByLevelOrderTraversal(root);

}