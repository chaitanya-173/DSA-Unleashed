#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    // check if the total sum is odd -> if yes, return false
    for(int i=0; i<n; i++) {
        sum += nums[i];
    }
    if(sum % 2 != 0) return false;
    sum /= 2;

    vector<vector<bool>> dp(n+1, vector<bool>(sum + 1, 0));
    // initialization
    for(int i=0; i<=n; i++) {
        dp[i][0] = true;
    }

    // dp
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    if(canPartition(nums)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
}