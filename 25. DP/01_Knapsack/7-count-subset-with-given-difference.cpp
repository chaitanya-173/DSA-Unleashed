#include <bits/stdc++.h>
using namespace std;

int countSubsetSumDP(vector<int>& arr, int sum, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  
  // Initialize first column
  for(int i = 0; i <= n; i++) dp[i][0] = 1;
  
  // Initialize first row
  for(int j = 1; j <= sum; j++) dp[0][j] = 0;
    
  // DP table filling
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= sum; j++) {
      if(arr[i-1] <= j) {
        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  
  return dp[n][sum];
}

int main() {
  vector<int> arr = {1,1,2,3};
  int difference = 1; 
  int n = arr.size();

  int sumOfArray = 0;
  for(int i = 0; i < n; i++) {
      sumOfArray += arr[i];
  }
  int sum = (difference + sumOfArray) / 2; // Calculate the target sum for subset

  cout << "Number of subsets with the given difference is " << countSubsetSumDP(arr, sum, n) << endl;
}