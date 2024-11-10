#include <iostream>
using namespace std;

int getSum(int* arr, int n){

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){

    int n;
    cin >> n;

    //Variable size array
    int* arr = new int[n]; //variable array created in HEAP

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Sum of array elements: " << ans << endl;

}