// Condition- elements entered in an array are in pairs and 
// only one element is unique (answer).

#include <iostream>
using namespace std;

int findUnique(int arr[], int size){
    int ans=0;
    for(int i=0; i<size; i++){
        ans = ans^arr[i];  // Doing XOR with same element cancels
    }                      // each other and at the end only unique
    return ans;            // element is left.
}
int main(){

    int size;
    cin >> size;

    int arr[size];

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "The unique element is: " << findUnique(arr, size);

}
