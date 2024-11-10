#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
    public:
        int data;
        int i;
        int j;

    //constructor
    Node(int data, int row, int col) {
        this -> data = data;
        i = row;
        j = col;
    }
};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare > minHeap;

    //step1: saare arrays ke first element insert krne hain
    for(int i=0; i<k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //step2: 
    while(minHeap.size() > 0) {
        Node* temp = minHeap.top();

        ans.push_back(temp -> data);
        minHeap.pop();

        int i = temp -> i;
        int j = temp -> j;

        if(j+1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;

}

int main() {

    int k;
    cout << "Enter number of arrays to be merged: ";
    cin >> k;

    int size;

    vector<vector<int> > array;

    for(int i=0; i<k; i++) {
        cout << "Enter size of " << i+1 << "th array: ";
        cin >> size;
        cout << "Enter elements of " << i+1 << "th array: ";
        for(int j=0; j<size; j++) {
            cin >> array[i][j];
        }
    }
    cout << endl;

    vector<int> ansArray = mergeKSortedArrays(array, k);

    for(int i=0; i<ansArray.size(); i++) {
        cout << ansArray[i] << " ";
    }


}
