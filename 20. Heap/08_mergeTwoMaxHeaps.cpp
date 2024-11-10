#include <iostream>
#include <vector>
using namespace std;

    vector<int> merge(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c;
        for(int i=0; i<n; i++) {
            c.push_back(a[i]);
        }
        for(int i=0; i<m; i++) {
            c.push_back(b[i]);
        }
        return c;
    }
    
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
        
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

void print(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
} 

int main() {

    vector<int> a{10, 5, 6, 2};
    vector<int> b{12, 7, 9};
    int n = a.size();
    int m = b.size();

    vector<int> c = merge(a, b, n, m);
        
    for(int i=(m+n)/2-1; i>=0; i--) {
        heapify(c, n+m, i);
    }
        
    print(c, m+n);

}