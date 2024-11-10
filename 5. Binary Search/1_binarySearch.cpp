#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;                   // "edge case"
    int mid = start + (end-start)/2;    // not '(start+end)/2' to avoid
                                        // adding of two indexes more  
    while(start <= end){                // than the range
        if(arr[mid] == key){
            return mid; 
        }

        else if(key > arr[mid]){
            start = mid+1;
        }
        
        else{
            end = mid-1;
        }

        mid = start + (end-start)/2;
    }

    return -1;
}

int main(){
    int even[6] = {3,4,6,8,9,13};
    int odd[5] = {2,5,7,10,15};

    cout << "Index of 9 is: " << binarySearch(even, 6, 9) << endl;
    cout << "Index of 5 is: " << binarySearch(odd, 5, 5) << endl;
    cout << "Index of 20 is: " << binarySearch(even, 6, 20) << endl;

}

