#include <iostream>
#include <vector>
using namespace std;

bool check(int arr[], int n){

    int count = 0;

    for(int i=1; i<n; i++){

        if(arr[i-1] > arr[i]){
            count++;
        }
    }

    if(arr[n-1] > arr[0])
    count++;

    return count<=1;

}

int main(){
    int arr[5] = {6,7,8,4,5};
    cout << check(arr, 5);
}

