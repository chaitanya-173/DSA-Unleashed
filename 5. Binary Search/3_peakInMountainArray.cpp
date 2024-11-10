#include <iostream>
using namespace std;

int peak(int arr[], int size){

    int strt = 0, end = size-1;
    int mid = strt + (end-strt)/2;

    while(strt<end){

        if(arr[mid] < arr[mid+1]){
            strt = mid+1;
        }

        else{
            end = mid;
        }

        mid = strt + (end-strt)/2;
        
    }
    return strt;
}

int main(){

    int arr[6] = {3,4,5,1};

    cout << "Peak element in mountain array is at index: " << peak(arr, 4) << endl;
    
}