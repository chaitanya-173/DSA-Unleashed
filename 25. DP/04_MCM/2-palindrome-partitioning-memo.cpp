// Palindrom Partioning - 2 (leetcode 132) { better solutions available without DP } 
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
  while(i < j) {
      if(s[i] != s[j]) return false;
      i++;
      j--;
  }
  return true;
}

int solve(string &s, int i, int j, vector<vector<int>> &dp) {
  // base case
  if(i >= j || isPalindrome(s, i, j)) return 0;
  
  if(dp[i][j] != -1) return dp[i][j];
  
  int mini = INT_MAX;
  for(int k=i; k<j; k++) {
      // for optimisation
      int left, right;                     // from here 
      if(dp[i][k] != -1) {    
          left = dp[i][k];
      } else {
          left = solve(s, i, k, dp);
          dp[i][k] = left;
      }
      if(dp[k+1][j] != -1) {
          right = dp[k+1][j];
      } else {
          right = solve(s, k+1, j, dp);
          dp[k+1][j] = right;
      }
      int temp = 1 + left + right;        // till here
      mini = min(mini, temp);
  }
  return dp[i][j] = mini;
}

int palPartition(string &s) {
  int n = s.size();
  vector<vector<int>> dp(n, vector<int> (n, -1));
  return solve(s, 0, n-1, dp);
}

int main() {
  string s = "manas";
  cout << "Minimum cuts needed for palindrome partitioning is: " << palPartition(s) << endl; // Output: 2 (m | ana | s)
}