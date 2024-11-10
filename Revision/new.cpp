#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> first, vector<int> second) {
    vector<int> ans;

    int i=0, j=0;
    while(i < first.size() && j < second.size()) {
        if(first[i] < second[j])
            ans.push_back(first[i++]);
        else
            ans.push_back(second[j++]);
    }

    while(i < first.size()) {
        ans.push_back(first[i++]);
    }

    while(j < second.size()) {
        ans.push_back(second[j++]);
    }

    return ans;
}

vector<int> mergeSort(vector<int> arr, int start, int end) {
    //base case
    if(start >= end) {
        return { arr[start] };
    }

    int mid = start + (end-start)/2;

    vector<int> leftArr = mergeSort(arr, start, mid);
    vector<int> rightArr = mergeSort(arr, mid+1, end);

    return merge(leftArr, rightArr);
}

int main() {

    vector<int> arr = {7,5,3,8,1,9,2,3};

    vector<int> ans = mergeSort(arr, 0, arr.size()-1);

    for(auto i: ans) {
        cout << i << " ";
    }

}