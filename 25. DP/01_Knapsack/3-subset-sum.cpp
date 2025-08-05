#include <iostream>
#include <vector> 
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
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

    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum)) {
        cout << "Found a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }
}