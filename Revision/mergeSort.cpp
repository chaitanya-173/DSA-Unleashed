#include <iostream>
using namespace std;

void printArray(int *a, int s) {
    for(int i = 0; i < s; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int mainArrayIndex = s;

    for(int i = 0; i < len1; i++) {
        arr1[i] = arr[mainArrayIndex++];
    }
    for(int i = 0; i < len2; i++) {
        arr2[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = s;
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if(arr1[i] < arr2[j]) {
            arr[mainArrayIndex++] = arr1[i++];
        } else {
            arr[mainArrayIndex++] = arr2[j++];
        }
    }
    while(i < len1) {
        arr[mainArrayIndex++] = arr1[i++];
    }
    while(j < len2) {
        arr[mainArrayIndex++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int s, int e) {
    if(s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main() {
    int arr[] = {1, 2, 5, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}
