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
}  //1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 -1 -1 8 -1 -1 -1

int getHeight(Node* root) {
    //base case
    if(root == NULL) {
        return 0;
    }

    int left = getHeight(root -> left);
    int right = getHeight(root -> right);

    int ans = max(left, right) + 1;
    return ans;
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);
    cout << "Height of BT: " << getHeight(root) << endl;
    cout << diaFast(root).first << endl;
    cout << diaFast(root).second  << endl; 

}

pair<int,int> diaFast(Node* root) {
    //base case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diaFast(root -> left);
    pair<int,int> right = diaFast(root -> right);

    int op1 = left.first;  //diameter of left part
    int op2 = right.first;  //diameter of right part
    int op3 = left.second + right.second + 1;  //left height + 1 + right height

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));   //tells diameter
    ans.second = max(left.second, right.second) + 1;   //tells height
}