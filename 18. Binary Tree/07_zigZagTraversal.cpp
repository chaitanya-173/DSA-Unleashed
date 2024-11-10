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

        cout << "Enter left node for " << temp -> data << ": ";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << ": ";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }  
    }
}

void printTreeByLevelTraversal(Node* &root) {
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

vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if(root == NULL)
        return result;
    
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();
        vector<int> ans(size);

        //level process
        for(int i=0; i<size; i++) {
            Node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if(frontNode -> left) 
                q.push(frontNode -> left);
            if(frontNode -> right) 
                q.push(frontNode -> right);
        }

        //direction change krenge
        leftToRight = !leftToRight;

        for(auto i: ans) {
            result.push_back(i);
        }

    }
    return result;
}

int main() {

    Node* root = NULL;
    buildTreeLevelWise(root);
    printTreeByLevelTraversal(root);
    
    vector<int> ans = zigZagTraversal(root);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

}