#include <iostream>
using namespace std;

bool linearSearch(int* arr, int size, int k){

    //base case: if the size is 0 then element not found
    if(size == 0)
    return false;

    //Recursive case
    if(arr[0] == k)
    return true;
    else{    //Recursion for the remaining part of the array
        bool remainingPart = linearSearch(arr+1, size-1, k);
        return remainingPart;
    }

}

int main(){

    int arr[6] = {1,3,4,9,6,2};
    int key = 9;
    int size = 6;

    bool ans = linearSearch(arr, size, key);

    if(ans)
    cout << "Element present" << endl;
    else
    cout << "Element not present" << endl;
    
}