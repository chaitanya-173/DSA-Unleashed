#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
  // base case
  if(i >= j) return 0;
  
  if(dp[i][j] != -1) return dp[i][j];
  
  int mini = INT_MAX;
  for(int k=i; k<j; k++) {
      int temp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1] * arr[k] * arr[j];
      mini = min(mini, temp);
  }
  
  return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr) {
  int n = arr.size();
  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
  return solve(arr, 1, n-1, dp);
}

int main() {
  vector<int> arr = {2, 1, 3, 4}; 
  cout << "Minimum number of multiplications is: " << matrixMultiplication(arr) << endl; // Output: 20
}