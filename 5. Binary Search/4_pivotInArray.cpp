#include <iostream>
using namespace std;

int getPivot(int arr[], int size){

    int strt = 0, end = size-1;
    int mid = strt + (end - strt)/2;

    while(strt<end){

        if(arr[mid] >= arr[0])
        strt = mid + 1;

        else
        end = mid;

        mid = strt + (end - strt)/2;
        
    }

    return mid;

}

int main(){

    int arr[5] = {7,9,1,2,3};

    cout << "The pivot element in this array is at index: " << getPivot(arr, 5);

}