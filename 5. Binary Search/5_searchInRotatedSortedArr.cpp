#include <iostream>
using namespace std;

int getPivot(int *arr, int size) {
    int start = 0, end = size-1;
    int mid = start + (end-start)/2;

    while(start < end) {
        if(arr[mid] >= arr[0])
            start = mid + 1;
        else 
            end = mid;
        
        mid = start + (end-start)/2;
    }
    return start;
}

int binarySearch(int *arr, int start, int end, int key) {
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] < key)
            start = mid+1;
        else if(arr[mid] > key)
            end = mid-1;
        else 
            return mid;
        mid = start + (end-start)/2;
    }
    return -1;
}

int search(int *arr, int size, int key) {
    int start = 0, end = size-1;
    int mid = start + (end-start)/2;
    int pivot = getPivot(arr, size);

    if(arr[pivot] <= key && key <= arr[size-1]) 
        return binarySearch(arr, pivot, size-1, key);
    else 
        return binarySearch(arr, 0, pivot-1, key);
    
}

int main() {

    int arr[] = {7,8,1,3,5};
    int size = 5;
    int key = 7;

    cout << search(arr, 5, key);



}