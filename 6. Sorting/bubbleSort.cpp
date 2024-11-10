#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n){
    
    for(int i=1; i<n; i++){ //for rounds
        bool swapped = false;
        for(int j=0; j<n-i; j++){

            if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped = true;
            }

        }
        if (swapped == false)
        break;

    }  //(n-i) better than (n-1) cuz elements are getting sorted

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

}

int main(){
    int arr[6] = {1,14,6,10,9,7};
    bubbleSort(arr, 6);
}

//bool for better optimization as if in best case an array is already sorted then break after 1st round only
//so time complexity in this case will become O(n);