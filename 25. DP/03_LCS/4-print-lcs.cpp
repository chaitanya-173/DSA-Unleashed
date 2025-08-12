#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2) {
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  // Step 1: Fill DP table with lengths
  for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if(s1[i-1] == s2[j-1]) {
              dp[i][j] = 1 + dp[i-1][j-1];
          } else {
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
  }

  // Step 2: Backtrack to get the actual LCS string
  int i = n, j = m;
  string ans = "";

  while(i > 0 && j > 0) {
      if(s1[i-1] == s2[j-1]) {
          ans += s1[i-1];
          i--;
          j--;
      }
      else if(dp[i-1][j] > dp[i][j-1]) {
          i--;
      }
      else {
          j--;
      }
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string s1 = "chaitanya";
  string s2 = "chaudhary";
  int n = s1.length();
  int m = s2.length();
  
  cout << findLCS(n, m, s1, s2); // output: "chaay"
  return 0;
}
