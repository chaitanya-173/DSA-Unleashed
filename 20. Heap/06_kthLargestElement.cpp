#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int> v, int k) {
        
        //min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        
        //step 1: make a heap from arr of size k
        for(int i=0; i<k; i++) {
            pq.push(v[i]);
        }

        //step 2: 
        for(int i=k; i<v.size(); i++) {
            if(v[i] > pq.top()) {
                pq.pop();
                pq.push(v[i]);          
            }
        }
        
        //step 3: ans is pq.top()
        int ans = pq.top();
        return ans;
        
    }

int main() {

    vector<int> arr{7, 10, 4, 3, 20, 15};
    int key = 3;

    cout << "Kth smallest element: " << kthLargest(arr, key) << endl;

}