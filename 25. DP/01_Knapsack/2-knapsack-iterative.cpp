#include <iostream>
#include <vector>
using namespace std;

int knapsackIterative(vector<int>& wt, vector<int>& values, int n, int W) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));
  
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=W; j++) {
      // if there is no item or capacity is 0
      if(i == 0 || j == 0) { 
        dp[i][j] = 0;
      } else if(wt[i-1] <= j) {
        // include the item
        dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j - wt[i-1]]);
      } else {
        // exclude the item
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp[n][W];
}

int main() {
  vector<int> wt = {1,2,3};
    vector<int> val = {4,5,1};
    int n = val.size();
    int capacity = 4;
  
  cout << "Maximum value that can be obtained: " << knapsackIterative(wt, val, n, capacity) << endl;
}