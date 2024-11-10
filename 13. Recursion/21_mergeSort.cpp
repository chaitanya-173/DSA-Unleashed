#include <iostream>
using namespace std;

void merge(int *arr, int s, int m, int e) {

    //get length of both the sorted arrays to be merged
    int len1 = m - s + 1;
    int len2 = e - m;

    //create 2 sorted arrays in heap(dynamically)
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values in first array
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    //copy values in second array
    mainArrayIndex = m + 1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else 
            arr[mainArrayIndex++] = second[index2++];
    }

    //agar dono array ki lengths different hai
    //first array was longer
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }
    //second array was longer
    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete first;
    delete second;

}

void mergeSort(int *arr, int s, int e) {
    //base case
    if(s >= e)
        return;

    int m = s + (e-s)/2;
    
    //left part sort krke aao
    mergeSort(arr, s, m);

    //right part sort krke aao
    mergeSort(arr, m+1, e);

    //merge 2 sorted arrays
    merge(arr, s, m, e);
}

int main() {

    int arr[] = {38,27,43,3,9,82,10};
    int n = 7;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

}