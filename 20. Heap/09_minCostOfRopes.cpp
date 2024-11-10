#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    vector<long long> arr{4,3,2,6};
    //create a min heap

        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
    
    cout << "Cost: " << cost << endl;

}