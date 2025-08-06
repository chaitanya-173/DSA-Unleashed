// Subset Sum Difference Proeblem use in this problem
#include <iostream>
#include <vector> 
using namespace std;

int minSubsetSumDiff(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Initialize: sum 0 is always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int mini = sum;  
    for(int i=0; i<sum/2 + 1; i++) {
        if(dp[n][i]) {
            mini = min(mini, sum - 2 * i);  // range from 0 to sum/2 (range - 2*i)
        }
    }
    
    return mini; 
}

int main() {
    vector<int> arr = {1,2,7};

    cout << "Minimum subset sum difference: " << minSubsetSumDiff(arr) << endl;
}