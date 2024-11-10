#include <iostream>
#include <queue>
using namespace std;

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {   //update nhi hua
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);   //niche walo ko bhi heap bnake laao
    }

}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {

        //step 1: swap
        swap(arr[1], arr[size]);
        size--;

        //step 2: heapify (place element to its correct position)
        heapify(arr, size, 1);
    }
}

int main() {
    
    cout << "Using priority queue here: " << endl;

    //max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element at top: " << pq.top() << endl;
    pq.pop();
    cout << "Element at top: " << pq.top() << endl;
    cout << "Size is: " << pq.size() << endl;
    cout << "Is empty or not: " << pq.empty() << endl; 

    cout << endl;
    
    //min heap
    priority_queue<int, vector<int>, greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at top: " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at top: " << minheap.top() << endl;
    cout << "Size is: " << minheap.size() << endl;
    cout << "Is empty or not: " << minheap.empty() << endl; 


}