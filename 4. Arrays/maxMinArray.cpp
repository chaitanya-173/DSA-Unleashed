#include <iostream>
#include <climits>
// #define INT_MAX 2147483647
using namespace std;

int getMin(int num[], int n) {
    int mini = INT_MAX;
    for(int i = 0; i<n; i++) {
        mini = min( mini, num[i]);   // predefined function
        //if(num[i] < mini){
        //    mini = num[i];
        //}
    }
    return mini;
}

int getMax(int num[], int n) {
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        maxi = max(maxi, num[i]);   // predefined function
        // if(num[i] > maxi){
        //   maxi = num[i];
        //}
    }
    return maxi;
}

int main(){

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int numArr[100];
    for(int i = 0; i<size; i++) {   //taking input in array
        cin >> numArr[i];
    }

    cout << "Maximum value is " << getMax(numArr, size) << endl;
    cout << "Minimum value is " << getMin(numArr, size) << endl;

}