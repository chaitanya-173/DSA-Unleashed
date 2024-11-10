#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size){
    for(int i=0, j=1; i<size, j<size; i+=2, j+=2){
        swap(arr[i], arr[j]);
    }
}

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arrEven[6] = {2,5,3,-8,6,4};
    int arrOdd[5] = {2,5,3,-8,6};

    swapAlternate(arrEven, 6);
    swapAlternate(arrOdd, 5);
    
    printArr(arrEven, 6);
    printArr(arrOdd, 5);
}

// for(int i=0; i<size; i+=2){
//     if(i+1 < size){
//         swap(arr[i], arr[i+1]);
//     }
// }
        
