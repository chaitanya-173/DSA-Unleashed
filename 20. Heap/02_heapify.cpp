#include <iostream>
using namespace std;

void heapifyMaxHeap(int arr[], int n, int i) {

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
        heapifyMaxHeap(arr, n, largest);   //niche walo ko bhi heap bnake laao
    }

}

//mistake
void heapifyMinHeap(int arr[], int n, int i) {

    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right <= n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {   //update nhi hua
        swap(arr[smallest], arr[i]);
        heapifyMinHeap(arr, n, smallest);   //niche walo ko bhi heap bnake laao
    }

}

int main() {
    
    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    int arr2[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //heap creation
    for(int i = n/2-1; i>0; i--) {
        heapifyMaxHeap(arr1, n, i);
    }

    cout << "Printing the array now: " << endl;
    for(int i=1; i<=n; i++) {
        cout << arr1[i] << " ";
    } cout << endl;


}