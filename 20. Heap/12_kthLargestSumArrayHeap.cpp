#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int getKthLargest(vector<int> arr, int k) {

    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];

            if(minHeap.size() < k) {
                minHeap.push(sum);
            }
            else {
                if(sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
    
}
   

int main() {

    vector<int> arr{1,2,6,4,3};

    cout << endl << getKthLargest(arr, 1);


}