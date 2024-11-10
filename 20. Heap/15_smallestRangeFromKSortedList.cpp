#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        int row;
        int col;
    
    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
    public:
        bool operator()(Node *a, Node *b) { 
            return (a->data > b->data); 
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare > minHeap;

    //step1: create a minHeap for starting element of each list & tracking min/max value
    for(int i=0; i<k; i++) {
        int element = a[i][0];   
        mini = min(mini, element);  
        maxi = max(maxi, element);
        minHeap.push(new Node(element,i, 0));
    }

    int range = maxi-mini;

    //process ranges
    while(!minHeap.empty()) {

        //mini fetch
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp -> data;

        //range or answer updation
        if(maxi-mini < range) {
            range = maxi-mini;
        }

        //next element exists
        if(temp -> col+1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
        }
        else {   //next element doesn't exist
            break;
        }

    }

    //returning the differnce
    return range+1;

}

int main() {

    vector<vector<int> > arr{ {4,10,11},{2,3,20},{5,6,12} };
    cout << kSorted(arr, 3, 3) << endl;
                                        
}