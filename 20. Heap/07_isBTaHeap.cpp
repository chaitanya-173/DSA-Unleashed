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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  //separator

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                //queue still have some child nodes
                q.push(NULL);  //separator
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
}  //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1


void buildFromLevelOrder(Node* &root) {   //second way to build a tree
    queue<Node*> q;
    cout << "Enter data for root: ";
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

int countNodes(struct Node* root) {
          //base case
        if(root == NULL)
            return 0;
        
        int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
        return ans;
        
      }
      
      bool isCBT(struct Node* root, int index, int count) {
        if(root == NULL) 
            return true;
        
        if(index >= count) 
            return false;
        else {
            bool left = isCBT(root -> left, 2*index + 1, count);
            bool right = isCBT(root -> right, 2*index + 2, count);
            return (left && right);
        }
      }
      
      bool isMaxOrder(struct Node* root) {
            //leaf node
            if(root -> left == NULL && root -> right == NULL) 
              return true;
            
            //only left node
            if(root -> right == NULL) {
                return (root -> data > root -> left -> data); 
            }
            else {   //both nodes
                bool left = isMaxOrder(root -> left);
                bool right = isMaxOrder(root -> right);
                
                return ( (left) && (right) && 
                (root -> data > root -> left -> data && root -> data > root -> right -> data) );
            }
      }
  
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalCount = countNodes(tree);
        if( isCBT(tree, index, totalCount) && isMaxOrder(tree) ) {
            return true;
        }
        else {
            return false;
        }
    }

int main() {

    Node* root = NULL;

    //creating a tree;
    buildFromLevelOrder(root);

    cout << "Printing level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Is heap or not: " << isHeap(root) << endl;

    

}