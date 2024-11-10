#include <iostream>
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

    if(largest != i) {   //check kro ki largest update hua hai ki nhi
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

    int arr[6] = {-1,6,3,9,1,8};
    int size = 5;

    cout << "Printing Unsorted array: " << endl;
    for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, size);

    cout << "Printing sorted array: " << endl;
    for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}