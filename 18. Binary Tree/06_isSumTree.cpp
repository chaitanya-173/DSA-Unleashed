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

pair<bool,int> isSumTree(Node* root) {
    //base case
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    if(root -> left == NULL && root -> right == NULL) {  //leaf node base case
        pair<bool,int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool,int> leftAns = isSumTree(root -> left);
    pair<bool,int> rightAns = isSumTree(root -> right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    
    bool condn = root -> data == leftAns.second + rightAns.second;

    pair<bool,int> ans;
    if( isLeftSumTree && isRightSumTree && condn ) {
        ans.first = true;
        ans.second = 2 * root -> data;
    }
    else {
        ans.first = false;
    }
    return ans;
}
 

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);
    cout << endl << "Sum tree: " << isSumTree(root).first << endl;

}

