#include <iostream>
using namespace std;

// Partition function to rearrange the elements
int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--; // Decrement j instead of incrementing i
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

// Recursive QuickSort function
void qs(int *arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

// Main function
int main() {
    int arr[] = {6, 4, 8, 2, 9, 1, 0, 7};
    int n = 8;

    // Perform QuickSort
    qs(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
