#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){

    //base case
    if(size == 0 || size == 1)
    return true;

    if(arr[0] > arr[1])
    return false;
    else{
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }

}

int main(){

    int arr[5];
    cout << "Enter array elements: " << endl;
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }

    bool ans = isSorted(arr,5);

    if(ans)
    cout << "Array is sorted" << endl;
    else
    cout << "Array is not sorted" << endl;

}