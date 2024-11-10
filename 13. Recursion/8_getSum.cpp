#include <iostream>
using namespace std;

int getSum(int* arr, int size){

    //base case
    if(size == 0)
    return 0;
    if(size == 1)
    return arr[0];

    //Recursive case
    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;

    return sum;

}

int main(){

    int arr[5];
    cout << "Enter array elements: " << endl;
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }

    cout << "Sum is: " << getSum(arr, 5);

}