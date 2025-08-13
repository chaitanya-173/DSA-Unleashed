#include <bits/stdc++.h>
using namespace std;

// This function can be be also used for finding the minimum insertions to make a string palindrome
int minDeletions(string s) {
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
    
  return n - dp[n][n]; // Minimum Deletions to make a string palindrome = Length of string - Length of LCS of string and its reverse
}

int main() {
  string s = "abcbda";
  cout << "Minimum Deletions to make Palindrome: " << minDeletions(s) << endl; // Output: 1
}