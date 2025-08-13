#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string &s) {
  string s2 = s;
  int n = s.size();
  
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
  for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
          if(s[i-1] == s2[j-1] && i != j) {
              dp[i][j] = 1 + dp[i-1][j-1];
          } else {
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
  }
  
  return dp[n][n];
}

int main() {
  string s = "axxzxy";
  cout << "Length of Longest Repeating Subsequence: " << LongestRepeatingSubsequence(s) << endl; // Output: 2
}