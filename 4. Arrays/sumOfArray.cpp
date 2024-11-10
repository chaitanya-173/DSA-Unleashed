#include <iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter size of array: ";
    cin  >> size;

    int sum = 0;

    int arr[30];
    for(int i=0; i<size; i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }

    cout << "Sum of array is: " << sum;

}
