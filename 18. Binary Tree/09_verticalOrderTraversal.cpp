#include <iostream>
#include <queue>
#include <vector>
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

vector<int> verticalTraversal(Node* root, vector<int> &ans) {
    map <int, map <int, vector<int> > > nodes;
    queue <pair <Node*, pair<int,int> > > q;
    
    if(root == NULL)
        return ans;
    
    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()) {
        pair <Node*, pair<int,int> > temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode -> data);

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1)));
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1)));
    }

    for(auto i: nodes) {
        for(auto j: i.second) {
            for(auto k: j.second) {
                ans.push_back(k);
            }
        } 
    }

    return ans;
}

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    vector<int> ans;
    verticalTraversal(root, ans);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

}