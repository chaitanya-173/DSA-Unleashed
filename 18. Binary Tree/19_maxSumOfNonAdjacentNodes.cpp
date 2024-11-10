#include <iostream>
#include <queue>
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

pair<int,int> solve(Node* root) {
    //base case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root -> left);
    pair<int,int> right = solve(root -> right);

    //backtracking (return kya kya krna hai:- )
    pair<int,int> result;
    result.first = root -> data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;   
}

int getMaxSum(Node* root) {
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    cout << getMaxSum(root) << endl;

}