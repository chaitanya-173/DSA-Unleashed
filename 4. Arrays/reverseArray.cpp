#include <iostream>
using namespace std;

void reverse(int arr[], int size){
    int start = 0;
    int end = size-1;
    while(start<=end){                // for(int i=0; i<(size/2); i++){         
        swap(arr[start], arr[end]);   //      swap(arr[i], arr[size-i-1]);
        start++;                      // }
        end--;
    }
}

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[6] = {2,4,6,8,5,7};
    int brr[5] = {1,4,7,9,0,};

    reverse(arr, 6);
    reverse(brr, 5);

    printArr(arr, 6);
    printArr(brr, 5);

}