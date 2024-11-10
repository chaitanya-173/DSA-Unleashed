// Condition- elements entered in an array are different till size 
// and only one element is unique (answer).

#include <iostream>
using namespace std;

int findDuplicate(int arr[], int size){
    int ans = 0;
    for(int i=0; i<size; i++){  //XOR ing all array elements
        ans = ans ^ arr[i];
    }
    for(int i=0; i<size; i++){  //XOR ing elements[1,n-1] with array
        ans = ans ^ i;   
    }
    return ans;
}

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "The duplicate element is: " << findDuplicate(arr, size);
}

// Method 2-  (complexity more cuz of 2 loops inside)

// #include <iostream>
// using namespace std;

// int findDuplicate(int nums[], int n){
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(nums[i] == nums[j]){
//                 ans = nums[j];
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     int n;
//     cin >> n;
    
//     int nums[n];
//     for(int i=0; i<n; i++){
//         cin >> nums[i];
//     }

//     cout << "The duplicate element in the array is: " << findDuplicate(nums, n);
// }
