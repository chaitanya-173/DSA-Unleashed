#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans){

    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, index+1, ans);  //original vector mein he changes ho jaynge (to save space comp)
        //backtrack
        swap(nums[index], nums[j]);  // to neutralise the swapping
    }

}

int main() {

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];
        } cout << "  ";
    }


}