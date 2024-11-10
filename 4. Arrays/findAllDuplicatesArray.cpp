// brute force approach
#include <iostream>  // (complexity more cuz of 2 loops)
using namespace std;

int findDuplicates(int nums[], int n){
    int arr[100], count=0;
    for(int i=0; i<n; i++){   // (n -> nums.size())
        for(int j=i+1; j<n; j++){
            if(nums[i] == nums[j]){
                cout << nums[i] << " ";  
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    int nums[n];
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    findDuplicates(nums, n);
}
