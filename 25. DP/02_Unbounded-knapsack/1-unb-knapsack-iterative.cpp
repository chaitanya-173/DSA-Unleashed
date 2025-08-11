#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity + 1));
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=capacity; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);  // max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
  vector<int> val = {6, 1, 7, 7};
  vector<int> wt = {1, 3, 4, 5};
  int capacity = 8;

  cout << "Maximum value in Knapsack = " << knapSack(val, wt, capacity) << endl;
}