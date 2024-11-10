#include <iostream>
using namespace std;

int printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
}

int insertionSort(int* arr, int n){

    for(int i=1; i<n; i++){

        printArray(arr, n);

        for(int j=i+1; j<n; j++){

            if(arr[j] < arr[i])
            swap(arr[j], arr[i]);

        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    int arr[5] = {4,9,2,1,3};
    insertionSort(arr, 5);

}