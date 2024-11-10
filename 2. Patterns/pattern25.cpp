#include <iostream>  // (complexity more cuz of 2 loops inside 
#include <climits>   // each other)
using namespace std;

int intersec(int arr[], int size1, int brr[], int size2){
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(arr[i] == brr[j]){
                cout << arr[i] << " ";
                brr[j]=INT_MIN;
            }
        }
    }
}
int main(){

    int size1, size2;
    cin >> size1 >> size2;

    int arr[size1];
    int brr[size2];

    for(int i=0; i<size1; i++){
        cin >> arr[i];
    }
    for(int j=0; j<size2; j++){
        cin >> brr[j];
    }

    intersec(arr, size1, brr, size2);
}
