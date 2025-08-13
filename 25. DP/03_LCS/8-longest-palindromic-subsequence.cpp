#include <bits/stdc++.h>
using namespace std;

// LPS(s) => LCS(s, reverse(s))
int longestPalinSubseq(string &s) {
  string s1 = s;
  reverse(s.begin(), s.end());
  int n = s.size();
  
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
  for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
          if(s[i-1] == s1[j-1]) {
              dp[i][j] = 1 + dp[i-1][j-1];
          } else {
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
  }
  
  return dp[n][n];
}

int main() {
  string s = "bbabcbcab";
  cout << "Length of Longest Palindromic Subsequence: " << longestPalinSubseq(s) << endl; // Output: 7
}
