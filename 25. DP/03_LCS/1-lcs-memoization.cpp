#include <iostream>
#include <vector>
using namespace std;

int lcs(string x, string y, int n, int m, vector<vector<int>> &dp) {
  // base case
  if(n == 0 || m == 0) return 0;

  // dp
  if(dp[n][m] != -1) return dp[n][m]; 
  
  // choice diagram
  if(x[n-1] == y[m-1]) {
      return dp[n][m] = 1 + lcs(x, y, n-1, m-1, dp);
  } else {
      return dp[n][m] = max(lcs(x, y, n-1, m, dp), lcs(x, y, n, m-1, dp));
  }
}

int longestCommonSubsequence(string text1, string text2) {
  int n = text1.length();
  int m = text2.length();
  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

  return lcs(text1, text2, n, m, dp);
}

int main() {
  string text1 = "chaitanya";
  string text2 = "chaudhary";
  cout << longestCommonSubsequence(text1, text2); // output: 5
}