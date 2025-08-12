#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of operations (insertions and deletions) required to convert s1 to s2
// using the Longest Common Subsequence (LCS) approach.
int minOperations(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int deletions = n - dp[n][m]; // 3 - characters in s1 not in LCS = 2
    int insertions = m - dp[n][m]; // 2 - characters in s2 not in LCS = 1
    
    return insertions + deletions; // Total operations needed
}

int main() {
  string s1 = "heap";
  string s2 = "pea";  
  cout << minOperations(s1, s2) << endl; // Output: 3
}