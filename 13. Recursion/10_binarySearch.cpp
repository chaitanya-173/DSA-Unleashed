#include <iostream>
using namespace std;

bool binarySearch(int* arr, int s, int e, int k){

    //base case (element not found) - while loop wala 
    if(s>e)
    return false;

    int mid = s + (e-s)/2;

    //base case (element found)
    if(arr[mid] == k)
    return true;

    //Recursive case
    if(arr[mid] < k) //right jao bhai
    return binarySearch(arr, mid+1, e, k);

    if(arr[mid] > k) //left jao bhai
    return binarySearch(arr, s, mid-1, k);

}

int main(){

    int arr[11] = {2,4,6,10,14,18,22,38,55,222};
    int size = 11;
    int key = 222;

    bool ans = binarySearch(arr, 0, size-1, key);
    if(ans)
    cout << "Element present" << endl;
    else
    cout << "Element not present" << endl;

}