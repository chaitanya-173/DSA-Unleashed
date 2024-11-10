#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    vector<int> mergedArr;
    int i = 0, j = 0;

    // Traverse both arrays and merge them into mergedArr
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) 
            mergedArr.push_back(arr1[i++]);
        else 
            mergedArr.push_back(arr2[j++]);
    }

    // Copy any remaining elements of arr1
    while (i < arr1.size()) {
        mergedArr.push_back(arr1[i++]);
    }

    // Copy any remaining elements of arr2
    while (j < arr2.size()) {
        mergedArr.push_back(arr2[j++]);
    }

    return mergedArr;
}

vector<int> mergeSort(vector<int> &arr, int s, int e) {
    // Base case
    if (s == e) 
        return { arr[s] }; // Return a single-element vector

    int m = s + (e - s) / 2;

    // Sort left part
    vector<int> leftArr = mergeSort(arr, s, m);

    // Sort right part
    vector<int> rightArr = mergeSort(arr, m + 1, e);

    // Merge two sorted arrays
    return mergeSortedArrays(leftArr, rightArr);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    vector<int> sortedArr = mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < sortedArr.size(); i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
