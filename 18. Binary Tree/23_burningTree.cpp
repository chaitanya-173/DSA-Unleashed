#include <iostream>
#include <queue>
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

    //func to create mapping & return target node
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &nodeToParent) {
        //level order traversal
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target) {
                res = front;
            }
                
            if(front -> left) {
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right) {
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*,Node*> &nodeToParent) {
        //level order traversal
        map<Node*,bool> visited;
        
        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        
        int time = 0;
        
        while(!q.empty()) {
            
            bool flag = 0;  //to check ki koi addition hua hai ki nhi
            
            int size = q.size();
            for(int i=0; i<size; i++) {
                //process neightbouring nodes
                Node* front = q.front();
                q.pop();
                
                if(front -> left && !visited[front -> left]) {  //left hogya
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                if(front -> right && !visited[front -> right]) {  //right hogya
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {  // parent hogya
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }  
            }
            if(flag == 1) {
                time++;
            }
        }
        return time;
    }
    
    int minTime(Node* root, int target) {
        //step 1: create node to parent mapping
        //step 2: find target node
        //step 3: burn the tree in min time
        
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        int time = burnTree(targetNode, nodeToParent);
        
        return time;
    }

int main() {

    Node* root = NULL;
    buildFromLevelOrder(root);
    printByLevelOrderTraversal(root);

    cout << minTime(root, 9) << endl;

}