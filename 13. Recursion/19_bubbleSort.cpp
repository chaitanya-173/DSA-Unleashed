#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size){

    //base case - (already sorted array)
    if(size == 0 || size == 1)
    return;

    //ek case hum solve kar dete hain (last element ko end mein fek dete hain)
    for(int i=0; i<size-i; i++){
        if(arr[i] > arr[i+1])
        swap(arr[i], arr[i+1]);
    }
    //baaki resursion dekh lega

    //Recurive call 
    bubbleSort(arr, size-1);

}

int main(){

    int arr[5] = {6,7,9,1,4};

    bubbleSort(arr, 5);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

}