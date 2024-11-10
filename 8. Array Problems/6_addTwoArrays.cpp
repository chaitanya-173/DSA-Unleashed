#include <iostream>
#include <math.h>
using namespace std;

int sum(int arr1[], int n, int arr2[], int m){

    int ans1 = 0;
    for(int i=0; i<n; i++){
        ans1 = (ans1 * 10) + arr1[i];
    }

    int ans2 = 0;
    for(int j=0; j<m; j++){
        ans2 = (ans2 * 10) + arr2[j];
    }

    return (ans1 + ans2);
}

int main(){
    int arr1[4] = {1,2,3,4};
    int arr2[1] = {6};
    cout << "Sum of both arrays is: " << sum(arr1, 4, arr2, 1);
}