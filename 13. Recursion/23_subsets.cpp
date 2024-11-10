#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solveSubsets(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){

    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solveSubsets(nums, output, index+1, ans);

    //include 
    output.push_back(nums[index]);
    solveSubsets(nums, output, index+1, ans);

    // backtrack to exclude the current element for further calls
    // output.pop_back();

}

int main() {

    vector<int> nums = {1,2,3};

    vector<int> output;
    int index = 0;
    vector<vector<int>> ans;
    solveSubsets(nums, output, index, ans);

    for(int i = 0; i < ans.size(); i++){
        cout << "{ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

}