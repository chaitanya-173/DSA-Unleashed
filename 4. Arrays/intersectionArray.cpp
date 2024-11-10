// Both the arrays are sorted in non-decreasing order

#include <iostream>   // (complexity more cuz of 2 loops inside
#include <climits>    // each other)
using namespace std;

int intersec(int arr[], int size1, int brr[], int size2){
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(arr[i] == brr[j]){
                cout << arr[i] << " ";   // ans.push_back(arr[i])
                brr[j]=INT_MIN;
                break;
            }
        }
    }
}

int main(){

    int size1, size2;
    cin >> size1 >> size2;

    int arr[size1];
    int brr[size2];

    for(int i=0; i<size1; i++){
        cin >> arr[i];
    }
    for(int j=0; j<size2; j++){
        cin >> brr[j];
    }

    intersec(arr, size1, brr, size2);
}

// Method 2- (Better approach)

// #include <iostream>
// #include <bits/stdc++.h> 
// #include <vector>
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
// 	int i=0, j=0;
// 	vector<int> ans;
// 	while(i<n && j<m){

// 		if(arr1[i] == arr2[j]){
// 			ans.push_back(arr1[i]);
// 			i++;
// 			j++;
// 		}

// 		else if(arr1[i] < arr2[j]){
// 			i++;
// 		}

// 		else{
// 			j++;
// 		}
// 	}
// 	return ans;
// }

