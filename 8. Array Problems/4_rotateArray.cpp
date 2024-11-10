#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int>& nums, int k) {
        
    vector<int> temp(nums.size());
    for(int i=0; i<nums.size(); i++){

        temp[(i+k) % nums.size()] = nums[i];
    }

    //copy temp into num vector
    nums = temp;
    return nums;
} 

void print(vector<int> ans){

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){

    vector<int> nums;
    nums.push_back(12);
    nums.push_back(24);
    nums.push_back(36);
    nums.push_back(48);
    nums.push_back(60);
    nums.push_back(72);

    for(int i: nums){
        cout << i << " ";
    }cout << endl;

    rotate(nums, 3);
    cout << "Rotated array -> ";
    print(nums);
}